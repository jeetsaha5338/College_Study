# -*- coding: utf-8 -*-
"""
Created on Sun Feb 18 15:36:58 2018

@author: User
"""

import os
import pandas as pd


#os.chdir("F:\\jeet\\jeet_ml\\ML\\project\\given")
os.chdir("H:\Data_Files")#for home
data= pd.read_csv("data_tenis.csv")
data=data.drop(["draw_size","tourney_id","tourney_name","tourney_date","winner_seed","loser_seed","winner_name","loser_name"],axis=1)
n=data.surface.unique()
a=n.shape
data['sur'] = data.surface.map({n[i]:i for i in range(a[0])})
data=data.drop(["surface"],axis=1)
n=data.tourney_level.unique()
a=n.shape
data['level'] = data.tourney_level.map({n[i]:i for i in range(a[0])})
data=data.drop(["tourney_level"],axis=1)
n=pd.concat([data.loser_hand, data.winner_hand]).unique()
a=n.shape
data['l_hand'] = data.loser_hand.map({n[i]:i for i in range(a[0])})
data['w_hand'] = data.winner_hand.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_hand","loser_hand"],axis=1)   
n=pd.concat([data.loser_id, data.winner_id]).unique()
a=n.shape
data['l_id'] = data.loser_id.map({n[i]:i for i in range(a[0])})
data['w_id'] = data.winner_id.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_id","loser_id"],axis=1)  
winner=data.filter(items=['sur','winner_rank_points','winner_ht','w_hand','winner_age','w_id','l_id','loser_rank_points','loser_ht','l_hand','loser_age'])
winner.head()
w=winner.rename(index=str,columns={'sur':'surface','winner_rank_points':'p_rank_points','winner_ht':'p_ht','w_hand':'p_hand','winner_age':'p_age','w_id':'p_id','l_id':'o_id','loser_rank_points':'o_rank_points','loser_ht':'o_ht','l_hand':'o_hand','loser_age':'o_age'})
w['win']=1
loser=winner
l=loser.rename(index=str,columns={'sur':'surface','loser_rank_points':'p_rank_points','loser_ht':'p_ht','l_hand':'p_hand','loser_age':'p_age','w_id':'o_id','l_id':'p_id','winner_rank_points':'o_rank_points','winner_ht':'o_ht','w_hand':'o_hand','winner_age':'o_age'})
l['win']=0
w.shape
l.shape
w.columns.values
l.columns.values

record=pd.concat([w,l],axis=0)
for p_d in record:
    md=record[p_d].median()
    record[p_d]=record[p_d].fillna(value=md)


record.to_csv('tennis_new.csv',sep=',')
