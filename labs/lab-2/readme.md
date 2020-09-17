 # Lab 2: IDE Intro, Function Runtime Timing

 Welcome to the first Data Structures Lab of Fall 2020! The goal of this lab will be to set up a functional environment and familiarize yourself with the differences in runtime for various functions and provide a basis for the study of various concepts of study in 212. **Be sure to read and follow all instructions unless otherwise specified. Record your answers to the questions in a text document named lab-01.txt** You'll find the table of contents for this lab below.

 1. [Introduction to Labs](#part-1-introduction-to-labs)
    - [Brief Rundown](#brief-rundown)
    - [Rules](#rules)
 2. [CS50 IDE](#part-2-cs50-ide)
    - [Setup](#21-ide-options---online-vs-offline)
    - [Getting Started](#22-getting-started)
 3. [Runtime differences](#part-3-runtime-differences)
    - [Euler's number (e)](#31-eulers-number-e)
    - [Fibonacci Problem](#32-fibonacci) 
 4. [Line Graphs](#part-4-line-graphs)
  5. [Max Subsequence Sum](#part-5-max-subsequence-sum)

 # [Part 1. Introduction to Labs](#lab-02-ide-intro-function-runtime-timing)

 ## [Brief Rundown](#lab-02-ide-intro-function-runtime-timing)

 Welcome to your first official CSC 212 Lab! Here is a brief rundown of how Labs will be run throughout the semester.

 * At the beginning of each Lab session, Christian will give a brief rundown of the day's exercises & answer any immediate questions students may have.
 * Following this, each of the TAs (Christian, Johann, and John) will split into a separate breakout room. All students will then be randomly assigned to one of the three rooms. This randomization is done via Zoom, so each week you will get re-shuffled.
 * Once in your assigned room, you are to work on the Lab assignment **individually**. You are of course encouraged to discuss the problem amongst yourselves and ask your assigned TA for help, but there will be **no** pair-programming/sharing of solutions.
 * At the end of Lab, upload your solution to Gradescope.

 ## [Rules](#lab-02-ide-intro-function-runtime-timing)

 1. Google it!
    - TAs are not your personal encyclopedia/knowledge base/code guru, etc. nor do we have the entirety of a language's libraries & their function's argument list memorized. We should not be your first stop when you get stuck on syntax. If you are having trouble finding a solution to your problem or finding/understanding the documentation that is a different story and we will be more than happy to assist. Expect the question "What have you googled?" to be asked from us throughout the semester.
 2. Webcams On!
    - During lab, please keep your webcams on so we can maintain the illusion of being in a proper lab setting as much as possible. This also makes it far easier for us to learn your names, remember questions you ask, etc.

 # [Part 2. CS50 IDE](#lab-02-ide-intro-function-runtime-timing)

 ## 2.1 IDE Options

### 2.1.2 CS 50 Online

The same IDE you have experience with from CSC 211 & the past week. One major weakness to remember is it requires you to be connected to the internet in order to use it. This means in the event of a power outage in your area, you will be left unable to work on any assignments. Even you prefer using CS50 Online, we **highly** recommend setting up an offline environment as a backup.

 ### 2.1.2 CS50 Offline

 If you choose to install the offline option (not recommended during this lab session due to time constraints), you can follow the instructions for setup [here](https://cs50.readthedocs.io/ide/offline/#).

>  CS50 IDE is a containerized application that runs on Docker.  Further details on: [Docker containers](https://www.docker.com/resources/what-container).

 ### 2.1.3 Other Options

 While CS50 IDE is strongly encouraged for this course, some other IDE options are:

 - [Visual Studio Code](https://code.visualstudio.com/)
 - [CLion](https://www.jetbrains.com/clion/) (Free with student id)
 - [QT C++](https://www.qt.io/developers/)

These IDEs may require more effort to learn and may seem less user-friendly at times, but they are much more professional and include many of the tools used in professional software production. While not necessary for this class, you may find it beneficial to yourself to spend some time learning one. Remember to keep in mind that Gradescope uses the 'g++' compiler, **you must ensure all code you submit is compatible with g++**! Other than this requirement, you are free to use whichever IDE you prefer.

 ## [2.2 Getting Started](#lab-02-ide-intro-function-runtime-timing)

 Now that your IDE is all set up, take some time and get to know it! Read through [this introduction](https://cs50.readthedocs.io/ide/online/)! 

 :white_check_mark: Question 1: Describe some major differences between using a local or online version of the IDE.

 :white_check_mark: Question 2: Where are your files stored if using the online version vs the offline version?

 :white_check_mark: Question 3: What are the PC and Mac hotkeys to create a new file?

 # [Part 3. Runtime differences](#lab-02-ide-intro-function-runtime-timing)

 The two mathematical equations that will be used in order to display the run time differences between more and less efficient implementations are finding Euler's number (e) and calculating Fibonacci numbers. You will be required to record the times of the various versions of both mathematical equations with  https://chart-studio.plot.ly/create/#/ . This is a website that allows you to very easily plot graphs via the input of a CSV file (Comma Separated Value). Creating this file will be explained later on. 

 ## [3.1 Euler's Number (e)](#lab-02-ide-intro-function-runtime-timing)

 ### What is Euler's number? 

 Euler's number (e), is a mathematical constant that is the base of the natural logarithm. This number is approximately equal to 2.71828. This number comes from Leonhard Euler (1707 - 1783). He was a Swiss mathematician, physicist, astronomer, geographer, logician, and engineer who made important and influential discoveries in many branches of mathematics. Another interesting fact on Euler is that he lost vision in his right eye early on in his career, he blamed it on his tendency to overwork himself while working on cartography for Petersburg Academy. This didn't stop him because 25 years later, he lost vision in his other eye for the same reason. 

 ### Euler(e) calculation functions 

 **Algorithm 1 for Euler's number**

 ```c++
 long double euler1(int n) {
     long double sum = 0;
     long double fact;
     for (int i = 0 ; i <= n ; i ++) {
         fact = 1;
         for (int j = 2 ; j <= i ; j++) {
             fact *= j;
         }
         sum += (1.0 / fact);
     }
 
     return sum;
 }
 ```

 **Algorithm 2 for Euler's number**

 ```c++
 long double euler2(int n) {
     long double sum = 0;
     long double fact = 1;
 
     for (int i = 0 ; i <= n ; i++) {
         sum += (1.0 / fact);
         fact *= (i+1);
     }
 
     return sum;
 }
 ```

 ### Function for Timing

 In order to be able to use the clock function you will **need to include the ctime library** in your program. This will allow for you to input the number you would like to calculate and the algorithm you would like to check. This code will not automatically create a file for you to submit to the plotting website. It is meant to allow you to compare the runtimes for a specific number between algorithms. 

 ```c++
 void time_func(uint16_t n, const char *name) {
 
     uint64_t val;
 
     unsigned long c_start, c_end;
 
     if (! strcmp(name, "euler1")) {
         c_start = std::clock();
         val = euler1(n);
         c_end = std::clock();
 
     }
     else if (! strcmp(name, "euler2")) {
         c_start = std::clock();
         val = euler2(n);
         c_end = std::clock();
 
     }
     else{
         std::cout << "Invalid function call" << std::endl;
 
     }
 
     float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
     std::cout << name << " euler(" << n << "):\t";
     std::cout << std::fixed << std::setprecision(4) << output << " Output: " << val << std::endl;
 }
 ```

 **Main Function**

 ```c++
 int main(int argc, char**argv) {
     if (argc != 3) {
         std::cout << "Usage: ./euler <n> <alg>\n";
         std::cout << "\t<n>\tn-th term to be calculated\n";
         std::cout << "\t<alg>\talgorithm to be used (euler1 or euler2)\n";
         return 0;
         
     }
 
     uint16_t n = (uint16_t) atoi(argv[1]);
     time_func(n, argv[2]);
 }
 
 ```

 Put the above functions into your ide and answer the questions that follow:

 :white_check_mark: Question 4. Play around with some small values of n. What is the first value of n that causes notably slower runtime for euler1?

 :white_check_mark: Question 5. What is the first value of n that causes notably slower runtime for euler2?

 ### Euler Runtime up to X numbers

 For this portion of the lab you **need to include the cstring library**

 As a disclaimer the functions euler1 and euler2 will not be changing for this section. However the time_func and main function will. The time_func will only differ slightly as you must change the return type to a float and then return the time output. 

 The purpose of this section is to restructure the previous section's handout so that it prints several values and their runtimes to the terminal, in order to see how runtime costs increase.

 For example if you enter ./euler 5 euler1, it will calculate and print euler(0) followed by euler(1) up to and including euler(5) and it will also calculate the time required to perform the calculation per value. 

 **Function for Timing**

 ```c++
 float time_func(uint16_t n, const char *name) {
     uint64_t val;
     unsigned long c_start, c_end;
 
     if (! strcmp(name, "euler1")) {
         c_start = std::clock();
         val = euler1(n);
         c_end = std::clock();
 
     }
     else if (! strcmp(name, "euler2")) {
         c_start = std::clock();
         val = euler2(n);
         c_end = std::clock();
 
     }
     else{
         std::cout << "Invalid function call" << std::endl;
         return 0;
 
     }
     
     float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
     return output;
 }
 
 ```

 **Main Function**

 ```c++
 int main(int argc, char**argv) {
     if (argc != 3) {
         std::cout << "Usage: ./euler <n> <alg>\n";
         std::cout << "\t<n>\tn-th term to be calculated\n";
         std::cout << "\t<alg>\talgorithm to be used (euler1 or euler2)\n";
         return 0;
     }
 
     uint16_t Max_Number = (uint16_t) atoi(argv[1]);
     
     for (int i = 0; i <= Max_Number; i++){
 
         float function_time = time_func(i, argv[2]);
         std::cout << argv[2] << "("<< i << ") Runtime took " << std::fixed << std::setprecision(4) << function_time << " Seconds\n";
         
     }
 
     return 0;
 }
 ```

 :white_check_mark: Question 6. Use the above code to compare the two Euler functions. Which function is faster? Why is it faster than the other?

 ## [3.2 Fibonacci](#lab-02-ide-intro-function-runtime-timing)

 ### What is Fibonacci? 

 Fibonacci is a mathematical formula that is used to calculate a number by adding the previous two numbers in order to form the next number. Leonardo Pisano (1170 - 1250) was an Italian mathematician who was most famous for his work with the Fibonacci Sequence. Unlike Leonhard Euler, he spent all his time as a mathematician, also unlike Euler, he maintained his vision.

 ### Fibonacci Runtime for specific numbers 

 **Algorithm 1 for Fibonacci**

 ```c++
 uint64_t fib_r(uint16_t n) {
     if (n < 2) {
         return n;
 
     } 
     else {
         return fib_r(n-1) + fib_r(n-2);
 
     }
 }
 ```

 **Algorithm 2 for Fibonacci**

 ```c++
 uint64_t fib_i(uint16_t n) {
 
     uint64_t sum;
     uint64_t prev[] = {0, 1};
 
     if (n < 2) {
         return n;
 
     }
 
     for (uint16_t i = 2 ; i <= n ; i++ ) {
         sum = prev[0] + prev[1];
         prev[0] = prev[1];
         prev[1] = sum;
 
     }
     return sum;
 }
 ```

 :white_check_mark: Question 7. Which function do you expect to run faster? Why?

 **Function for Timing**
 In order to be able to use the clock function you will **need to include ctime** in your program. This will allow for you to input the number you would like to calculate and the algorithm you would like to check. This code will not automatically create a file for you to submit to the plotting website. It is meant to allow you to compare the runtimes for a specific number between algorithms. 

 ```c++
 void time_func(uint16_t n, const char *name) {
     uint64_t val;
     unsigned long c_start, c_end;
     if (! strcmp(name, "fib_i")) {
         c_start = std::clock();
         val = fib_i(n);
         c_end = std::clock();
 
     }
     else if (! strcmp(name, "fib_r")) {
         c_start = std::clock();
         val = fib_r(n);
         c_end = std::clock();
 
     }
     else{
         std::cout << "Invalid function call" << std::endl;
         return;
 
     }
     
     float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
     std::cout << name << " fib(" << n << "):\t";
     std::cout << std::fixed << std::setprecision(4) << output << " Output: " << val << std::endl;
 }
 ```

 **Main Function**

 ```c++
 int main(int argc, char**argv) {
     if (argc != 3) {
         std::cout << "Usage: ./fib <n> <alg>\n";
         std::cout << "\t<n>\tn-th term to be calculated\n";
         std::cout << "\t<alg>\talgorithm to be used (fib_r or fib_i)\n";
         return 0;
         
     }
 
     uint16_t n = (uint16_t) atoi(argv[1]);
     time_func(n, argv[2]);
 }
 
 ```

 :white_check_mark: Question 8. Use the above code to compare the two Fibonacci functions on similar inputs. Which function was faster? Why do you think it is faster than the other?

 ### Fibonacci Runtime up to X numbers 

 For this portion of the lab you **need to include the fstream and cstring libraries** 

 As a disclaimer the functions fib_i and fib_r will not be changing for this section. However the time_func and main function will. The time_func will only differ slightly as you must change the return type to a float and then return the time output. 

 The purpose of this section is to restructure the code from the previous section to create a csv file that you will be able to input into the graphing website. This program will create a CSV file that contains the Fibonacci number for every number up to your input. 

 For example if you enter ./fib 5 fib_r, it will calculate fib(0), fib(1), ..., fib(5) and it will also calculate the time per value. 

 **Function for Timing**

 ```c++
 float time_func(uint16_t n, const char *name) {
 uint64_t val;
     unsigned long c_start, c_end;
     if (! strcmp(name, "fib_i")) {
         c_start = std::clock();
         val = fib_i(n);
         c_end = std::clock();
 
     }
     else if (! strcmp(name, "fib_r")) {
         c_start = std::clock();
         val = fib_r(n);
         c_end = std::clock();
 
     }
     else{
         std::cout << "Invalid function call" << std::endl;
 
     }
 
     float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;;
     return output;
 }
 
 ```

 **Main Function**

 ```c++
 int main(int argc, char**argv) {
     if (argc != 3) {
         std::cout << "Usage: ./fib <n> <alg>\n";
         std::cout << "\t<n>\tn-th term to be calculated\n";
         std::cout << "\t<alg>\talgorithm to be used (fib_r or fib_i)\n";
         return 0;
     }
 
     uint16_t Max_Number = (uint16_t) atoi(argv[1]);
     std::ofstream myfile;
     
     myfile.open(std::to_string(Max_Number)+ "_" + (char *)argv[2]+".csv");
 
     myfile << "input" << "," << "time" << '\n';
 
     for (int i = 0; i <= Max_Number; i++){
         float function_time = time_func(i, argv[2]);
         myfile << i << "," << std::fixed << std::setprecision(4) << function_time<<'\n';
         
     }
     myfile.close();
     return 0;
 }
 
 ```

  The code above can be used to generate a csv for upload to the plot.ly website.

  :white_check_mark: Question 9.Modify the above code to work for the Euler functions from the previous program. 

 # [Part 4. Line Graphs](#lab-02-ide-intro-function-runtime-timing)

 Once you have the required csv files you will need to go to https://chart-studio.plot.ly/create/#/ . 

 Once you're on this website you will click the import button that is located at the top right of the windows browser. You will then click upload and upload the csv file you would like to display. 

 After this is complete you will click the trace button. Here you will be able to select what you want to display on your x and y axis. Display input for the x axis and time for the y axis. 

 When you're uploading another csv to this website you will repeat the same steps above. 

 The final deliverable for this lab will include an image of the graph you make to show the differences in runtime. This will require an account with plot.ly to save the image or alternatively you could use the snipping tool to take a screenshot of your plot.

 # [Part 5. Max Subsequence Sum](#lab-02-ide-intro-function-runtime-timing)

 Now that you've had some experience timing functions, lets try something different. Here are four samples of code that all solve the same problem. These should look familiar, as we discussed a similar problem & went over a few solutions during last week's lab.

The 'Max Subsequence Sum' problem is the task of finding a contiguous subsequence of the largest sum of a sequence of n numbers. In other words were you to make 2 cuts into the sequence, what is the highest the sum of all numbers between those cuts could be? For each function, read through and make a prediction on how fast each will run.

 If it helps you to follow the code, all functions listed will return '11' for the array {4, -3, 5 -2, -1, 2, 6, -2} (everything except the -2 at the end.)

 ```c++
 int MaxSubSum1(std::vector<int> a) {
 	int maxSum = 0;
 	for (int i = 0; i < a.size(); ++i) {
 		for (int j = 1; j < a.size(); ++j) {
 			int thisSum = 0;
 
 			for (int k = i; k <= j; ++k) {
 				thisSum += a[k];
 			}
 
 			if (thisSum > maxSum) {
 				maxSum = thisSum;
 			}
 		}
 	}
 	return maxSum;
 }
 ```

 ```c++
 int MaxSubSum2(std::vector<int> a) {
 	int maxSum = 0;
 
 	for (int i = 0; i < a.size(); ++i) {
 		int thisSum = 0;
 
 		for (int j = i; j < a.size(); ++j) {
 			thisSum += a[j];
 
 			if (thisSum > maxSum) {
 				maxSum = thisSum;
 			}
 		}
 	}
 	return maxSum;
 }
 ```

 ```c++
 int MaxSubSum3(std::vector<int> a){
     int sum = 0;
     int max_sum = 0;
     int min_sum = 0;
     int min_index = 0;
     int max_start = 0;
     int max_end = 0;
     
     for(unsigned int i = 0; i < a.size(); i++){
         sum += a[i];
         
         if(sum < min_sum){
             min_sum = sum;
             min_index = i;
         }
         
         if(sum - min_sum > max_sum){
             max_sum = sum - min_sum;
             max_start = min_index + 1;
             max_end = i + 1;
         }
     }
     return max_sum;
 }
 ```

 ```c++
 int MaxSubSum4(std::vector<int> a) {
 	int max_so_far = 0;
 	int max_ending_here = 0;
 
 	for (unsigned int i = 0; i < a.size(); i++) {
 		max_ending_here += a[i];
 
 		if (max_so_far < max_ending_here) {
 			max_so_far = max_ending_here;
 		}
 
 		if (max_ending_here < 0) {
 			max_ending_here = 0;
 		}
 	}
 	return max_so_far;
 }
 ```

Here is an updated 'time_func' function for use with these functions. Each time 'time_func' is called in main, it will add a new value to the vector prior to timing it. The result is there will always be 'n' elements in the vector where 'n' is the value of 'i' in main();

```c++
float time_func(uint16_t n, const char *name) {
    uint64_t val;
    unsigned long c_start, c_end;
    // 'static' makes it so this vector is "shared" amongst all invocations of this function
    static std::vector<int> int_vector;
    // Add a random number between -20 20 to the vector
    if(n > 0){
        int_vector.push_back(rand() % 41 - 20);
    }
    
    if(! strcmp(name, "maxsubsum1")){
        c_start = std::clock();
        val = MaxSubSum1(int_vector);
        c_end = std::clock();
    }
    else{
        std::cout << "Invalid function call" << std::endl;
    }
    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    return output;
}
```



 :white_check_mark: Question 10. Modify again your timing code to work for each of these functions, and graph them on https://chart-studio.plot.ly/create/#/. Do your graphs match what you expected?

 # What to submit

 You should submit your answer document `lab-01.txt` and images of the plots you were able to create for sections 3 & 5 to Gradescope. 
