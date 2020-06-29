#!/usr/bin/env python3
import tensorflow
import sys
import numpy as np

def main(framebgrsmall = sys.argv[1]):
    print(framebgrsmall)
    # Load the TFLite model and allocate tensors.
    interpreter = tensorflow.lite.Interpreter(model_path="detect.tflite")
    interpreter.allocate_tensors()

    # Get input and output tensors.
    input_details = interpreter.get_input_details()
    output_details = interpreter.get_output_details()

    # Test the model on random input data.
    input_shape = input_details[0]['shape']
    input_data = np.array(np.random.random_sample(input_shape), dtype=np.float32)
    interpreter.set_tensor(input_details[0]['index'], input_data)

    interpreter.invoke()

    # The function `get_tensor()` returns a copy of the tensor data.
    # Use `tensor()` in order to get a pointer to the tensor.
    output_data = interpreter.get_tensor(output_details[0]['index'])
    print(output_data)

if __name__ == '__main__':
    main()