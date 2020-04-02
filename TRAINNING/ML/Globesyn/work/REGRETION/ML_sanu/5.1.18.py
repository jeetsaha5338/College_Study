import glob

import numpy as np
files_tr = glob.glob("D:\AOT\Programings\Machine_Learning_Training\ML\mlaudiotest1\ArijitRafi_train\*.wav")
#print(files_tr)
import librosa

y,srr= librosa.load(files_tr[0])
s= librosa.feature.mfcc(y,sr=srr)
s = s.flatten()
print(s.size)

arr_train = np.empty((s.size))

for file in files_tr:
    print("Reading: " + file)
    y1,sr1= librosa.load(file)
    s1= librosa.feature.mfcc(y1,sr=sr1)
    s1 = s1.flatten()
    arr_train = np.vstack((arr_train,s1))
print(arr_train[1:,].shape)
