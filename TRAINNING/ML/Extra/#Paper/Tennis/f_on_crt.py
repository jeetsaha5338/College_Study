import os
import numpy as np
import pandas as pd
os.chdir("E:\Data_Files")#for home
data= pd.read_csv("data_tenis.csv")

n=data.surface.unique()
a=n.shape
data['sur'] = data.surface.map({n[i]:i for i in range(a[0])})
data=data.drop(["surface"],axis=1)

n=pd.concat([data.loser_id, data.winner_id]).unique()
a=n.shape
data['l_id'] = data.loser_id.map({n[i]:i for i in range(a[0])})
data['w_id'] = data.winner_id.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_id","loser_id"],axis=1)

winnner=data.filter(items=['sur','w_id','w_ace', 'w_df', 'w_svpt', 'w_1stIn', 'w_1stWon','w_2ndWon', 'w_SvGms', 'w_bpSaved','w_bpFaced' ,
                           'l_id', 'l_ace', 'l_df', 'l_svpt', 'l_1stIn', 'l_1stWon', 'l_2ndWon', 'l_SvGms', 'l_bpSaved','l_bpFaced'])

winnner.columns.values
winnner.shape
winnner.head()
w=winnner.rename(index=str,columns={'w_id':'p_id','l_id':'o_id','sur':'surface',
                                 'w_ace':'p_ace', 'w_df':'p_df', 'w_svpt':'p_svpt', 'w_1stIn':'p_1stIn', 'w_1stWon':'p_1stWon',
                                 'w_2ndWon':'p_2ndWon','w_SvGms':'p_SvGms', 'w_bpSaved':'p_bpSaved','w_bpFaced':'p_bpFaced', 
                                 'l_ace':'o_ace', 'l_df':'o_df', 'l_svpt':'o_svpt', 'l_1stIn':'o_1stIn', 'l_1stWon':'o_1stWon',
                                 'l_2ndWon':'o_2ndWon','l_SvGms':'o_SvGms', 'l_bpSaved':'o_bpSaved','l_bpFaced':'o_bpFaced'})
w['win']=1
loser=winnner
l=loser.rename(index=str,columns={'sur':'surface','w_id':'o_id','l_id':'p_id',
                                 'w_ace':'o_ace', 'w_df':'o_df', 'w_svpt':'o_svpt', 'w_1stIn':'o_1stIn', 'w_1stWon':'o_1stWon',
                                 'w_2ndWon':'o_2ndWon','w_SvGms':'o_SvGms', 'w_bpSaved':'o_bpSaved','w_bpFaced':'o_bpFaced', 
                                 'l_ace':'p_ace', 'l_df':'p_df', 'l_svpt':'p_svpt', 'l_1stIn':'p_1stIn', 'l_1stWon':'p_1stWon',
                                 'l_2ndWon':'p_2ndWon','l_SvGms':'p_SvGms', 'l_bpSaved':'p_bpSaved','l_bpFaced':'p_bpFaced'})
l['win']=0


record=pd.concat([w,l],axis=0)

for p_d in record:
    md=record[p_d].median()
    record[p_d]=record[p_d].fillna(value=md)

index=np.random.permutation(record.shape[0])
record=record.iloc[index,:]

record.to_csv('tennis_mod1.csv',sep=',',index=False)
