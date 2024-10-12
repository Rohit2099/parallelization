import os
import pickle

matrix_sizes = [32, 64, 128, 256, 512, 1024, 2048, 4096]

programs = ['sequential', 'pthreads', 'openmp']

data = {}

for program in programs:
    data[program] = []
    for dimension in matrix_sizes:
        os.system('gcc ' + program + '.c' + ' -fopenmp -o ' + program)
        os.system('./' + program + ' ' + str(dimension))
        with open("time.txt", "r") as txt_file:
            lines = txt_file.readlines()
            data[program].append(float(lines[0]))
# SAVE
with open("data_2.pkl", "wb") as pkl_handle:
	pickle.dump(data, pkl_handle)

