import os
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn import model_selection 
from sklearn import metrics
import matplotlib.pyplot as plt
os.chdir("E:\STUDY\Data_Files")
pima=pd.read_csv("pima_diabetics.csv")
#print(dibe)
y=pima['class']
#type(y)
X=pima.drop("class",axis=1)#search on the header coloumn rowwise
#type(X)
X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.25,random_state=42)
model=linear_model.LogisticRegression()
model.fit(X_train,y_train)

predicted=model.predict(X_test)
#predicted


conf_mat=metrics.confusion_matrix(y_test,predicted)
print(conf_mat)
#acc_score=(conf_mat[0,0]+conf_mat[1,1])/(conf_mat[0,0]+conf_mat[1,1]+conf_mat[0,1]+conf_mat[1,0])
#print("acuracy :",acc_score)
acc_score=metrics.accuracy_score(y_test,predicted)
print("acuracy :",acc_score)
prec_score=metrics.precision_score(y_test,predicted)
print("precition :",prec_score)
rec_score=metrics.recall_score(y_test,predicted)
print("recall :",rec_score)
auc_score=metrics.roc_auc_score(y_test,predicted)
print("auc :",auc_score)

model.predict_proba(X_test)
y_score=model.decision_function(X_test)
#print("y_score :",y_score)
type(y_score)
y_score[:10]
len(y_score)
len(X_test)

conf_mat=metrics.confusion_matrix(y_test,predicted)
print(conf_mat)



#for checking the default value
predicted1=(y_score >= 0).astype(np.int)
print(predicted1)

conf_mat=metrics.confusion_matrix(y_test,predicted1)
print(conf_mat)



#cheak the range
np.max(y_score)
np.min(y_score)



#for 3
predicted2=(y_score >= 3).astype(np.int)
print(predicted1)

conf_mat=metrics.confusion_matrix(y_test,predicted2)
print(conf_mat)

#for 1
predicted3=(y_score >= 1).astype(np.int)
print(predicted1)

conf_mat=metrics.confusion_matrix(y_test,predicted3)
print(conf_mat)

acc_score=metrics.accuracy_score(y_test,predicted3)
print("acuracy :",acc_score)
prec_score=metrics.precision_score(y_test,predicted3)
print("precition :",prec_score)
rec_score=metrics.recall_score(y_test,predicted3)
print("recall :",rec_score)
auc_score=metrics.roc_auc_score(y_test,predicted3)
print("auc :",auc_score)

#for 1.5
predicted3=(y_score >= 1.5).astype(np.int)
print(predicted1)

conf_mat=metrics.confusion_matrix(y_test,predicted3)
print(conf_mat)

acc_score=metrics.accuracy_score(y_test,predicted3)
print("acuracy :",acc_score)
prec_score=metrics.precision_score(y_test,predicted3)
print("precition :",prec_score)
rec_score=metrics.recall_score(y_test,predicted3)
print("recall :",rec_score)
auc_score=metrics.roc_auc_score(y_test,predicted3)
print("auc :",auc_score)

#for 0.5
predicted3=(y_score >= 0.5).astype(np.int)
print(predicted1)

conf_mat=metrics.confusion_matrix(y_test,predicted3)
print(conf_mat)

acc_score=metrics.accuracy_score(y_test,predicted3)
print("acuracy :",acc_score)
prec_score=metrics.precision_score(y_test,predicted3)
print("precition :",prec_score)
rec_score=metrics.recall_score(y_test,predicted3)
print("recall :",rec_score)
auc_score=metrics.roc_auc_score(y_test,predicted3)
print("auc :",auc_score)






#for graph
precition,recall,threshold=metrics.precision_recall_curve(y_test,y_score)
for p,r,t in zip(precition,recall,threshold):
    print("Treshold : {:.4f} , Precition : {:.4f} , Recall : {:.4f}".format(t,p,r))

plt.plot(threshold,precition[:-1],'r--')
plt.plot(threshold,recall[:-1],'g--')

plt.plot(precition[:-1],recall[:-1],'b--')
plt.plot(recall[:-1],precition[:-1],'b--')#precition recall carve

fpr,tpr,threshold=metrics.roc_curve(y_test,y_score)
plt.plot(fpr,tpr)#roc_auc curve
















