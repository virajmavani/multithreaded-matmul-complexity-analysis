rm A B C_singleThread C_multiThread prog1 prog2 gmA gmB check

# Generate Matrix A
echo "Generating Matrix A..."
gcc generatingMatrixA.c -o gmA -std=c99 -w
./gmA > A
echo "Matrix A generated!"

echo "Generating Matrix B..."
# Generate Matrix B
gcc generatingMatrixB.c -o gmB -std=c99 -w
./gmB > B
echo "Matrix B generated!"

echo "Multiplying in Single Thread..."
# Multiply Single Thread
gcc Prog1.c -o prog1 -std=c99 -w
date
./prog1 > C_singleThread
echo "Single Thread Multiplication Done!"
date

# Multiply Multi Thread
echo "Multiplying in multiple threads..."
gcc Prog2.c -o prog2 -std=c99 -pthread -w
date
./prog2 > C_multiThread
echo "Multi-threaded Multiplication Done!"
date

# Check whether both are same
echo "Checking if same..."
gcc checkSingleMulti.c -o check -std=c99 -w
./check
echo "Check Performed!"

rm prog1 prog2 gmA gmB check
