using System;
using System.Numerics;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            long num = long.Parse(Console.ReadLine());
            if (num == 0 || num == 1) {
                Console.WriteLine(1);
                return ;
            }
            Console.WriteLine(Factorial(1, num));
        }
        
        static BigInteger Factorial(long start, long end) {
            if (start >= end) return new BigInteger(start);
            if (end - start == 1) return new BigInteger(start) * end;
    
            long mid = (start + end) / 2;
            return Factorial(start, mid) * Factorial(mid+1, end);   
        }
    }
}