echo "enter :"
read n
k=0
s=0

	m=$n
	while [ $m -gt 0 ]
	do
		m=`echo "$m / 10"|bc`
		k=`echo "$k + 1"|bc`
	done
	m=$n
	while [ $m -gt 0 ]
	do
		t=`echo "$m % 10"|bc`
		t1=1
		for((j=1;j<=k;j=j+1))
		do
			t1=`echo "$t1 * $t"|bc`
		done
		s=`echo "$s + $t1"|bc` 
		m=`echo "$m / 10"|bc`
	done
	ca=`echo "scale = 3;$s==$n"|bc`
	if [ $ca -eq 1 ]
	then
		echo "Armstrong"
	fi

