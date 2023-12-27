#Подключаем библиотеки
import tensorflow as tf
from tensorflow import keras
import numpy as np

#xor
train_input = np.asarray([[0, 0], [0, 1], [1, 0], [1, 1]])
train_output = np.asarray([0, 1, 1, 0])

model = keras.Sequential([
    keras.layers.Dense(4, input_shape=(2,), activation=tf.nn.tanh),
    keras.layers.Dense(1, activation=tf.nn.sigmoid),
])

model.compile(optimizer=tf.keras.optimizers.Adam(), 
              loss='binary_crossentropy',
              metrics=['accuracy'])

model.fit(train_input, train_output, epochs=500)

#xor
test_input = np.asarray([[0, 0], [0, 1], [1, 0], [1, 1]])
test_output = np.asarray([0, 1, 1, 0])

test_loss, test_acc = model.evaluate(test_input, test_output)
print('Test accuracy:', test_acc)

for layer in model.layers:
    print('Layer: ', layer.name, '\nWieghts: ', layer.weights)

