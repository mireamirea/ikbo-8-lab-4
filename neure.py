from pybrain.datasets            import SupervisedDataSet
from pybrain.tools.shortcuts     import buildNetwork
from pybrain.supervised.trainers import BackpropTrainer
import cPickle as pickle
import numpy as np
import sys
'''
Для работы с нейроными сетями используется библиотека PyBrain
Для ее подключения необходимо установить библиотеку Numpy,cPickle,scipy
'''
data = SupervisedDataSet(3, 1)

data.addSample([0,0,0],[0]) #1
data.addSample([0,0,1],[0])	#2
data.addSample([0,1,0],[0])	#3
data.addSample([0,1,1],[0])	#4
data.addSample([1,0,0],[1])	#5
data.addSample([1,0,1],[0])	#6
data.addSample([1,1,0],[1]) #7
data.addSample([1,1,1],[1])	#8



if sys.argv[1] == "training":


	print (sys.argv[2])
	neure = buildNetwork( data.indim, 3 , data.outdim )
	trainingg = BackpropTrainer(neure, dataset=data, verbose=True)
	for i in xrange(int(sys.argv[2])):
		trainingg.trainEpochs(1)
		print ('\tvalue  %d : %.2f'%(i, neure.activate([sys.argv[3],sys.argv[4],sys.argv[5]])[0]))
	pickle.dump(neure, open('Networkfile.dump', 'w'))
if len(sys.argv) == 4:
	neure = pickle.load(open('Networkfile.dump'))
	trainingg = BackpropTrainer(neure, dataset=data, verbose=True)
	trainingg.trainEpochs(1)
	print ('value: %.2f'%(neure.activate([sys.argv[1],sys.argv[2],sys.argv[3]])[0]))