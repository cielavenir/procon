#!/usr/bin/python

# MNIST For ML Beginners!

# This tutorial is intended for readers who are new to both machine learning and TensorFlow.
# Just like programming has Hello World, machine learning has MNIST.
# MNIST is a simple computer vision dataset. It consists of images of handwritten digits.
# Source: https://goo.gl/B14py7

# Please help us to improve this section by sending us your
# feedbacks and comments on: https://docs.google.com/forms/d/16fH20Qf8gJ2o31Vnlss2uLJ7wL9vq76TeUGqghTY0uI/viewform

# Importing input data
import random
import input_data
mnist = input_data.read_data_sets(raw_input(), raw_input(), raw_input())

import tensorflow as tf
x = tf.placeholder(tf.float32, [None, 784])
W = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))
y = tf.nn.softmax(tf.matmul(x, W) + b)
y_ = tf.placeholder(tf.float32, [None, 10])
cross_entropy = tf.reduce_mean(-tf.reduce_sum(y_ * tf.log(y), reduction_indices=[1]))
train_step = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy)
init = tf.initialize_all_variables()

sess = tf.Session()
sess.run(init)
for i in range(1000):
	batch_xs, batch_ys = mnist.train.next_batch(100)
	sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys})

result = sess.run(tf.argmax(y,1), feed_dict={x: mnist.validation.images})
print ' '.join(map(str, result))