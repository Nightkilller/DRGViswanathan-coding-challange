Day 35 of the #DrGViswanathanChallenge!

Today’s practice focused on Array Optimization, Prefix Products, Suffix Products, and Greedy Problem Solving, helping me strengthen my understanding of how to optimize brute-force solutions using multiple passes.

✅ LeetCode 238 – Product of Array Except Self

Solved the problem using Prefix Product + Suffix Product.

The key idea was to calculate the product of all elements except the current element without using division.

I used:
• Prefix Product → stores the product of all elements to the left
• Suffix Product → calculates the product of all elements to the right
• Two-Pass Approach → combines prefix and suffix products efficiently
• In-Place Optimization → uses the output array to avoid an additional prefix/suffix array
• No Division → handles zero values naturally

For example, for:

nums = [1, 2, 3, 4]

The resulting array is:

[24, 12, 8, 6]

The main observation was that:

answer[i] = prefix[i] × suffix[i]

Instead of creating separate prefix and suffix arrays, I first stored prefix products in the answer array and then multiplied the suffix product during a reverse traversal.

This helped reduce the extra space complexity to O(1), excluding the output array.

✅ Codeforces – E. Busy Beaver

Solved the problem using Greedy Strategy + Prefix Feasibility + Priority-Based Processing.

The key challenge was to determine how to construct the maximum possible number of floors when completing one project can increase the available capital and enable further construction.

The solution required carefully analyzing which contracts can currently be completed and how completing them affects the available capital.

This problem helped me understand:
• Greedy decision making
• Capital/resource management
• Dependency between sequential operations
• Feasibility of building prefixes
• Efficient processing of multiple projects

Key Takeaways:

🔹 Strengthened my understanding of prefix and suffix techniques
🔹 Learned how to eliminate unnecessary auxiliary arrays
🔹 Practiced solving array problems without division
🔹 Improved my understanding of O(n) optimization
🔹 Learned how to approach problems involving limited resources
🔹 Practiced greedy strategies for maximizing achievable results
🔹 Improved my ability to identify dependencies between operations
🔹 Continued building consistency in DSA and Competitive Programming

Another productive day of problem solving! 💻🚀

Two more problems solved, adding Prefix/Suffix Products, Array Optimization, Greedy Thinking, and Resource Management to my toolkit.

Consistency is the key to improving in DSA and competitive programming! 🔥

#DrGViswanathanChallenge #Day35 #LeetCode #Codeforces #DSA #Arrays #PrefixProduct #SuffixProduct #Greedy #Optimization #CompetitiveProgramming #ProblemSolving #CPlusPlus #CodingJourney #100DaysOfCode
