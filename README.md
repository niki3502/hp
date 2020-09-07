g++ -o test test.c -lhts
./test > test.txt

g++ -o count count.c -lhts
count ref/rCRS.fasta.gz > count.txt

g++ -o hp hp.c -lhts
./hp fasta/f1.fa >hp1.txt;./hp fasta/f2.fa >hp2.txt;./hp fasta/f3.fa >hp3.txt;./hp fasta/f4.fa >hp4.txt;./hp fasta/f5.fa >hp5.txt;./hp fasta/f6.fa >hp6.txt;./hp fasta/f7.fa >hp7.txt;./hp fasta/f8.fa >hp8.txt;./hp fasta/f9.fa >hp9.txt;./hp fasta/f10.fa >hp10.txt;./hp fasta/f11.fa >hp11.txt;

HOW TO RUN EBD
1. get mpileup file:
samtools mpileup -f ref.fa in.bam > mpileup.txt
2. compile ebd.c
gcc -o ebd ebd.c -lhts
3. run ebd
./ebd mpileup.txt
