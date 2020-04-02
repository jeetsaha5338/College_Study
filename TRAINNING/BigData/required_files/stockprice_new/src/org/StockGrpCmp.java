package org;

import org.apache.hadoop.io.WritableComparable;
import org.apache.hadoop.io.WritableComparator;

public class StockGrpCmp extends WritableComparator{
	
	public StockGrpCmp(){
		super(SPKey.class,true);
	}
	
	@Override
	public int compare(WritableComparable a, WritableComparable b) {
		// TODO Auto-generated method stub
		SPKey k1 = (SPKey)a;
		SPKey k2 = (SPKey)b;
		return k1.getSymbol().compareTo(k2.getSymbol());
	}

}
