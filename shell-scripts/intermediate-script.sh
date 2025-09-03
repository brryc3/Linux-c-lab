#!bin/bash
#--- Conditional ---
read -p "Enter a number: " NUM
if [ $NUM -gt 10 ]; then 
	echo  "Greater than 10"
else
	echo "10 or less"
fi

#--- Loop --_
for i in {1..5}; do 
	echo "Iteration $i"
done

#--- Function ---
greet() {
	echo "Hello from function!"
}
greet
