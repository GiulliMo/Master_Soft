from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import pyaudio
import tensorflow as tf
import deepspeech
import argparse
from tensorflow.python.ops import gen_audio_ops as contrib_audio
import tensorflow.compat.v1 as tfv1
import numpy as np
import wave

#--input_arrays=previous_state_c, input_samples,input_node, input_lengths --output_arrays='logits', 'mfccs',  'metadata_feature_win_len', 'metadata_version', 'metadata_sample_rate', 'new_state_h', 'new_state_c', 'metadata_alphabet', 'metadata_feature_win_step'
#[[1, 2048],[512],[1, 2048],[1, 16, 19, 26],[1]]
from tensorflow_core.lite.python.lite import Optimize


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

#converter = tf.lite.TFLiteConverter.from_frozen_graph(
      # graph_def_file, input_arrays, output_arrays)
#converter.allow_custom_ops = True
#converter.post_training_quantize = True
#converter.optimizations = [Optimize.DEFAULT]
#tflite_model = converter.convert()
#open("converted_model1.tflite", "wb").write(tflite_model)


interpreter = tf.lite.Interpreter("models/output_graph.tflite")

interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

print(input_details)
print(output_details)

#input_shape = input_details[2]['shape']
#input_data = np.array(np.random.random_sample(input_shape), dtype=np.float32)
#interpreter.set_tensor(input_details[2]['index'], input_data)

#interpreter.invoke()

# The function `get_tensor()` returns a copy of the tensor data.
# Use `tensor()` in order to get a pointer to the tensor.
#output_data = interpreter.get_tensor(output_details[5]['index'])




filename = "test.wav"

sample_rate = 16000
win_len = 32
win_step = 32
audio_window_samples = sample_rate*(win_len/1000)
n_input = 26
n_context = 9


def getBuffer( w):
    frames = w.getnframes()
    buffer = w.readframes(frames)
    type(buffer)
    return (buffer)

buffer = getBuffer(wave.open(filename, 'r'))
print(len(buffer))
data16 = np.frombuffer(buffer, dtype=np.int16)
data=data16
waveFile = wave.open("test2.wav", 'wb')
waveFile.setnchannels(1)
waveFile.setsampwidth(pyaudio.PyAudio().get_sample_size(pyaudio.paInt16))
waveFile.setframerate(16000)
waveFile.writeframes(b''.join(data))
waveFile.close()


filename = "stream.wav"

session_config = tfv1.ConfigProto(allow_soft_placement=True, log_device_placement=False,
                                        inter_op_parallelism_threads=0,
                                        intra_op_parallelism_threads=0,
                                        gpu_options=tfv1.GPUOptions(allow_growth=False))

with tfv1.Session(config=session_config) as session:
    samples = tf.io.read_file(filename)
    decoded = contrib_audio.decode_wav(samples, desired_channels=1)
    spectrogram = contrib_audio.audio_spectrogram(decoded.audio, window_size=audio_window_samples, stride=win_step, magnitude_squared=True)

    features = contrib_audio.mfcc(spectrogram=spectrogram,sample_rate=sample_rate,  dct_coefficient_count=n_input, upper_frequency_limit=sample_rate/2)
    features = tf.reshape(features, [-1, n_input])
    features_len = tf.shape(input=features)[0]


    previous_state_c = np.zeros([1, 2048])
    previous_state_h = np.zeros([1, 2048])

    features = tf.expand_dims(features, 0)
    features_len = tf.expand_dims(features_len, 0)


    batch_size = tf.shape(input=features)[0]

    window_width = 2 * n_context + 1
    num_channels = n_input

    # Create a constant convolution filter using an identity matrix, so that the
    # convolution returns patches of the input tensor as is, and we can create
    # overlapping windows over the MFCCs.
    eye_filter = tf.constant(np.eye(window_width * num_channels)
                                   .reshape(window_width, num_channels, window_width * num_channels), tf.float32) # pylint: disable=bad-continuation

    # Create overlapping windows
    batch_x = tf.nn.conv1d(input=features, filters=eye_filter, stride=1, padding='SAME')

    # Remove dummy depth dimension and reshape into [batch_size, n_windows, window_width, n_input]
    batch_x = tf.reshape(batch_x, [batch_size, -1, window_width, num_channels])

    #print(batch_x.eval(session=session))
    features = batch_x.eval(session=session)
    features_len = features_len.eval(session=session)

    interpreter.set_tensor(input_details[0]['index'], features)
    interpreter.set_tensor(input_details[1]['index'], np.float32(previous_state_c))
    interpreter.set_tensor(input_details[2]['index'], np.float32(previous_state_h))
    #interpreter.set_tensor(input_details[3]['index'], np.float32(features_len))
    interpreter.invoke()

    output_data = interpreter.get_tensor(output_details[0]['index'])

    print(output_data)
    print("yo")
    print(np.squeeze(output_data))