import argparse
import tensorflow as tf
import deepspeech
from tensorflow.python.framework import tensor_util
import horovod.tensorflow as hvd
from numpy import reshape
from tensorflow.keras import datasets, layers, models
import matplotlib as plt
import numpy as np
import os


def initModel():

    # saver = tf.train.import_meta_graph('model.ckpt-54800.meta')

    # These are set to the default names from exported models, update as needed.
    filename = "models/output_graph.pb"

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
        with tf.Session() as sess:
            # or creating the writer inside the session
            tf.compat.v1.summary.FileWriter('graphs', sess.graph)
            model = deepspeech.Model(graph,500)
    print("load finished")

    return graph, wts


if __name__ == '__main__':

    graph, wts = initModel()

    for qp in graph.get_operations():
        print(qp.name)

    x = graph.get_tensor_by_name('net/input_node:0')
    y = graph.get_tensor_by_name('net/logits:0')
    print(x)
    print(y)

    #for n in wts:
   #     print "Name of the node - %s" % n.name
     #   print "Value - "
      #  print tensor_util.MakeNdarray(n.attr['value'].tensor)

    exit()
