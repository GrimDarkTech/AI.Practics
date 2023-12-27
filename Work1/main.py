#Подключаем библиотеки
import tensorflow as tf
from tensorflow import keras
import numpy as np
import time

#train
train_input = np.random.random(size=(1000, 10))

train_output = np.argmin(train_input, axis=1)/10

model = keras.Sequential([
    keras.layers.Dense(10, input_shape=(10,)),
    keras.layers.Dense(10, activation=tf.nn.relu),
    keras.layers.Dense(5, activation=tf.nn.relu),
    keras.layers.Dense(1),
])

model.compile(optimizer=tf.keras.optimizers.Adam(), 
              loss='mean_absolute_error',
              metrics=['accuracy'])

model.fit(train_input, train_output, epochs=10)

#test
test_input = np.random.random(size=(500, 10))


test_output = np.argmin(test_input, axis=1)


test_loss, test_acc = model.evaluate(test_input, test_output)
print('Test accuracy:', test_acc)

for i in range(0, 10):
    X_new = np.random.rand(1, 10)  # Новый массив из 10 элементов
    prediction = model.predict(X_new)
    print("\n\n ABBOBA ", X_new, " fact: ", np.argmin(X_new))
    print("Предсказанное минимальное значение:", prediction[0, 0] * 10)

t1 = time.time()
for i in range(1000000):
    val  = np.argmin(np.random.rand(1, 10))
print(time.time() - t1, "ms")

input()