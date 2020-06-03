from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import tensorflow as tf
import tflite_runtime as tflite
import deepspeech
import argparse

import numpy as np

#--input_arrays=previous_state_c, input_samples,input_node, input_lengths --output_arrays='logits', 'mfccs',  'metadata_feature_win_len', 'metadata_version', 'metadata_sample_rate', 'new_state_h', 'new_state_c', 'metadata_alphabet', 'metadata_feature_win_step'
#[[1, 2048],[512],[1, 2048],[1, 16, 19, 26],[1]]

def initModel():

    # saver = tf.train.import_meta_graph('model.ckpt-54800.meta')

    # These are set to the default names from exported models, update as needed.
    filename = "models-DE/output_graph.pb"

    # Import the TF graph
    with tf.io.gfile.GFile(filename, 'rb') as f:
        graph_def = tf.compat.v1.GraphDef()
        graph_def.ParseFromString(f.read())

    with tf.Graph().as_default() as graph:
        # The name var will prefix every op/nodes in your graph
        # Since we load everything in a new graph, this is not needed
        tf.import_graph_def(graph_def, name='net')
        graph_nodes = [n for n in graph_def.node]
        wts = [n for n in graph_nodes if n.op == 'Const']
      #  with tf.Session() as sess:
            # or creating the writer inside the session
       #     tf.compat.v1.summary.FileWriter('graphs', sess.graph)
    print("load finished")

    return graph, wts


if __name__ == '__main__':
    filename = "models-DE/output_graph.pb"
    graph, wts = initModel()

    for qp in graph.get_operations():
        abc = graph.get_tensor_by_name(qp.name + ":0")
        print(abc)

graph_def_file = "models-DE/output_graph.pb"
input_arrays = ["previous_state_c", "input_samples", "previous_state_h", "input_node", "input_lengths"]
output_arrays = ["logits", "mfccs",  "metadata_feature_win_len", "metadata_version", "metadata_sample_rate", "new_state_h", "new_state_c", "metadata_alphabet", "metadata_feature_win_step"]
#input_arrays=[{'name': 'previous_state_c', 'index': 405, 'shape': np.array([1, 2048], dtype=np.int32), 'dtype': <class 'numpy.float32'>, 'quantization': (0.0, 0), 'quantization_parameters': {'scales': array([], dtype=float32), 'zero_points': array([], dtype=int32), 'quantized_dimension': 0}}, {'name': 'input_samples', 'index': 380, 'shape': array([512], dtype=int32), 'dtype': <class 'numpy.float32'>, 'quantization': (0.0, 0), 'quantization_parameters': {'scales': array([], dtype=float32), 'zero_points': array([], dtype=int32), 'quantized_dimension': 0}}, {'name': 'previous_state_h', 'index': 406, 'shape': array([   1, 2048], dtype=int32), 'dtype': <class 'numpy.float32'>, 'quantization': (0.0, 0), 'quantization_parameters': {'scales': array([], dtype=float32), 'zero_points': array([], dtype=int32), 'quantized_dimension': 0}}, {'name': 'input_node', 'index': 379, 'shape': array([ 1, 16, 19, 26], dtype=int32), 'dtype': <class 'numpy.float32'>, 'quantization': (0.0, 0), 'quantization_parameters': {'scales': array([], dtype=float32), 'zero_points': array([], dtype=int32), 'quantized_dimension': 0}}]
input_shapes={"previous_state_c" : [1, 2048], "previous_state_h" : [1, 2048], "input_samples" : [512], "input_node" : [1, 16, 19, 26], "input_lengths" : [1]}

converter = tf.lite.TFLiteConverter.from_frozen_graph(
       graph_def_file, input_arrays, output_arrays)
converter.allow_custom_ops = True
converter.post_training_quantize = True
converter.optimizations = [tf.lite.Optimize.OPTIMIZE_FOR_SIZE]
tflite_model = converter.convert()
open("converted_model1.tflite", "wb").write(tflite_model)


interpreter = tf.lite.Interpreter("models-DE/output_graph.tflite")
interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

print(input_details)
print(output_details)

input_shape = input_details[2]['shape']
input_data = np.array(np.random.random_sample(input_shape), dtype=np.float32)
interpreter.set_tensor(input_details[2]['index'], input_data)

interpreter.invoke()

# The function `get_tensor()` returns a copy of the tensor data.
# Use `tensor()` in order to get a pointer to the tensor.
output_data = interpreter.get_tensor(output_details[5]['index'])
print(output_data)

