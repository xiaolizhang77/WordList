# 结对项目-最长英语单词链

作者：张启立

团队成员：张启立  李震

### 0 前言

| 项目                                     | 内容                                                         |
| :--------------------------------------- | :----------------------------------------------------------- |
| 这个作业属于哪个课程                     | [2023年北航敏捷软件工程](http://t.csdn.cn/C8Kkl)             |
| 这个作业的要求在哪里                     | [结对项目-最长英语单词链](https://bbs.csdn.net/topics/613883108) |
| 我在这个课程的目标是                     | 初步尝试了解结队编程，体会结队编程的优势                     |
| 这个作业在哪个**具体方面**帮助我实现目标 | 让我亲自尝试结队编程，让我感受到结队编程的优势               |

### 1 项目地址

- 教学班级：周四班
- 项目地址：https://github.com/xiaolizhang77/WordList/tree/master

### 2 项目计划

#### PSP表格

| **PSP2.1**                              | **Personal Software Process Stages**    | **预估耗时（分钟）** | **实际耗时（分钟）** |
| :-------------------------------------- | :-------------------------------------- | :------------------- | :------------------- |
| Planning                                | 计划                                    | 60                   | 30                   |
| · Estimate                              | · 估计这个任务需要多少时间              | 20                   | 10                   |
| Development                             | 开发                                    | 500                  | 1000                 |
| · Analysis                              | · 需求分析 (包括学习新技术)             | 500                  | 600                  |
| · Design Spec                           | · 生成设计文档                          | 300                  | 600                  |
| · Design Review                         | · 设计复审 (和同事审核设计文档)         | 200                  | 100                  |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) | 300                  | 250                  |
| · Design                                | · 具体设计                              | 200                  | 250                  |
| · Coding                                | · 具体编码                              | 500                  | 600                  |
| · Code Review                           | · 代码复审                              | 300                  | 200                  |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）  | 200                  | 300                  |
| Reporting                               | 报告                                    | 500                  | 500                  |
| · Test Report                           | · 测试报告                              | 20                   | 60                   |
| · Size Measurement                      | · 计算工作量                            | 20                   | 20                   |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          | 100                  | 30                   |
|                                         | 合计                                    | 3720                 | 4550                 |

### 3 看教科书和其它资料中关于 Information Hiding，Interface Design，Loose Coupling 的章节，说明你们在结对编程中是如何利用这些方法对接口进行设计的

1. Information Hiding： 在结对编程中，我们将模块内部的实现细节隐藏起来，仅暴露必要的接口给其它模块使用。这可以通过使用访问修饰符（如 public，private 和 protected）来实现。通过隐藏实现细节，我们可以更好地维护代码的封装性和安全性，并避免不必要的耦合。
2. Interface Design： 良好的接口设计可以提高代码的可读性和可维护性。在结对编程中，我们共同设计接口，确保它们清晰地定义了模块之间的交互方式，并遵循 SOLID 原则中的接口隔离原则。这可以确保每个接口都只包含其它模块所需的最小信息，并且不会受到其它模块的影响。
3. Loose Coupling： 松散耦合是指模块之间的依赖性最小化。在结对编程中，我们遵循 SOLID 原则中的依赖反转原则，确保模块之间仅依赖于抽象接口而不是具体实现。这可以减少代码的耦合度，并且使代码更容易测试和维护。

### 4 计算模块接口的设计与实现过程

#### 第一阶段目标：实现一个命令行的计算最长英语单词链的程序

##### 总体思路：

​		将输入的单词按照首尾字母进行分类，也就是26*26个类别。通过首尾字母是否有单词，可以构成一个有向图，程序以找到有向图中最长路径为目标。

##### 需求1基本思路：

​		使用`dfs`计算每两个字符之间的链有哪些，通过这些链经过的节点，结合单词表进行排列组合，找出所有的链。

​		基本步骤：创建一个二维数组表示字母之间的边（edge），以及一个结构体数组（word_list）来存储单词。将输入的单词添加到 `word_list` 中，同时更新 `edge` 数组。使用 `find_chain` 函数在 `edge` 数组中查找所有可能的路径，然后将结果存储在 `allChain` 变量中。针对每一个路径，使用 `print_word_chain` 函数打印单词链。在这个过程中，还可以根据需要满足的条件进行筛选。将最终的单词链结果存储在 `chain` 变量中。

##### 需求2基本思路：

​		使用`dijkstra`算法计算每个字符为起始字符时最长链长度，然后找出起始字符最长的一条作为结果。longest_chain使用动态规划计算每个节点作为终点的最长链长度，并逆序构建路径。function2And4使用深度优先搜索（DFS）遍历有向图，从起点开始探索所有可能路径，直到到达终点。在遍历过程中，比较并更新最长路径。最后，将找到的最长路径及其长度分别存储到给定的指针变量中。

##### 需求3基本思路：

​		和需求2基本一致，只不过需求2使用的有向图边取值为0或者1，而需求3有向图为单词长度。

##### 需求4基本思路：

​		当有首尾字符规定时，使用`dfs`计算符合要求的链有哪些，结合单词表找到最长链。

##### 需求5基本思路：

​		只需要将有向图中对应字符的边设置为0即可。

##### 需求6基本思路：

​		使用深度优先搜索（DFS）方法遍历 map2d 中的单词，寻找符合条件的最长单词链。使用 `search` 和 `searchUseInApi` 函数根据指定的条件（如指定的开头字母 para_h，结尾字母 para_t，以及是否排除指定的字母 para_j）调用 `dfs` 函数，并记录找到的最长单词链。我们提供了一个 API 函数 searchUseInApi，用于在外部调用时传入指定的单词列表、开头字母、结尾字母等条件，并返回最长单词链的结果。

#### 第二阶段

项目封装函数如下：

```c
int gen_chains_all(char *words[], int len, vector<vector<string>> &result);

int gen_chain_word(char *words[], int len, vector<string> &result, char head, char tail, char reject, bool enable_loop);

int gen_chain_char(char *words[], int len, vector<string> &result, char head, char tail, char reject, bool enable_loop);
```

### 5 编译无警告

以下是项目编译过程中无警告截图：

![image_0](images\image_0.png)

### 6 UML 图

由于代码编写采用面向过程的方式，因此这里展示文件组织形式以及核心代码函数调用关系：

文件组织结构：

![文件组织](images\文件组织.png)

函数调用关系：

![函数调用关系](images\函数调用关系.png)

### 7 计算模块接口部分的性能改进

在需求1的计算过程中，消耗最大的函数是 `findPaths` 和 `print_word`。这些函数中包含了递归调用，可能导致大量的计算。为了提高性能，我们尝试了以下策略：

1. 优化递归：递归可能导致大量的函数调用。尝试将递归转换为迭代，或者使用动态规划或记忆化搜索，以避免重复计算。
2. 剪枝：在 `findPaths` 函数中，在递归过程中检查某些条件，以便在不满足条件时提前结束递归。例如，如果找到的路径长度已经超过当前已知最短路径，可以停止继续搜索该路径。
3. 数据结构优化：使用更高效的数据结构来存储和处理数据。例如，可以考虑使用哈希表、平衡二叉搜索树等数据结构来提高查找、插入和删除操作的性能。

在需求2和3的计算过程中，消耗最大的函数可能是 `dfs`。这个函数使用递归来查找指定起点和终点之间的最长链。为了提高性能，我们尝试了以下策略：

1. 优化递归：递归可能导致大量的函数调用。尝试将递归转换为迭代，或者使用动态规划或记忆化搜索，以避免重复计算。
2. 剪枝：在 `dfs` 函数中，在递归过程中检查某些条件，以便在不满足条件时提前结束递归。例如，如果找到的路径长度已经超过当前已知最长路径，可以停止继续搜索该路径。

在需求6的计算过程中，最消耗资源的函数是 `dfs()` 和 `search()`。为了提高程序性能，我们采取以下策略：

1. 剪枝：在 `dfs()` 函数中，我们在搜索过程中进行剪枝，通过剪枝，我们可以减少无效搜索，从而提高程序性能。
2. 使用动态规划：`search()` 函数的实现可以通过动态规划方法进行优化。将问题分解成子问题，并存储子问题的解，避免重复计算。对于这个问题，我们为每个字母和单词长度建立一个表格，存储从该字母开始、单词长度为指定长度的最长单词链。这样，在计算过程中，我们可以查表获得子问题的解，而不是重复计算。

### 8 阅读 Design by Contract，Code Contract 的内容，并描述这些做法的优缺点，说明你是如何把它们融入结对作业中的

Design by Contract（契约式设计）是一种软件开发方法，它强调在代码实现之前，先明确代码应该满足的约束条件。Code Contract则是微软在.NET框架中实现的一种契约式设计工具，可以用来在代码中定义和检查各种契约条件，包括前置条件、后置条件和不变量等。它们的主要优缺点如下：

优点：

1. 契约式设计可以帮助开发人员更加清晰地定义代码的期望行为和限制条件，可以提高代码的可读性和可维护性。
2. Code Contract可以在编译期和运行期对代码进行契约条件检查，可以及早发现潜在的错误和异常，从而提高代码的可靠性和稳定性。
3. 契约式设计可以帮助开发人员更好地理解和处理代码之间的依赖关系，可以减少代码的耦合度，从而提高代码的重用性和扩展性。

缺点：

1. 契约式设计需要开发人员在编写代码时，投入更多的时间和精力来定义和检查契约条件，可能会增加开发成本。
2. Code Contract需要使用专门的工具来进行契约条件的定义和检查，可能需要额外的学习成本和开发环境支持。
3. 契约式设计和Code Contract的应用范围受到一定限制，不适用于所有类型的代码和应用场景。

在结对作业中，我们可以将契约式设计和Code Contract融入到代码开发过程中，来提高代码的质量和可靠性。具体做法包括：

1. 在讨论需求和设计方案时，我们可以一起讨论并明确代码应该满足的契约条件，包括前置条件、后置条件和不变量等。
2. 在编码时，我们可以使用Code Contract工具来定义和检查契约条件，可以及早发现潜在的错误和异常，从而提高代码的可靠性和稳定性。
3. 在代码审查和改进过程中，我们可以共同检查和完善契约条件，从而提高代码的可读性和可维护性。

通过将契约式设计和Code Contract融入到结对作业中，我们可以更好地协作和协调，同时还能够提高代码的质量和可靠性。

### 9 测试

#### 文件结构

![image_1](images\image_1.png)

​		在我们的项目中，测试部分的目的是验证程序功能的正确性。具体来说，测试部分的核心是对 `libword_list.dll` 动态链接库中定义的函数进行测试。这个库提供了一系列用于处理单词链的功能。项目中的测试部分包含以下几个文件：

1. `CMakeLists.txt`：定义了如何构建和组织测试部分的 CMake 配置文件。
2. `test_wordlist.cpp`：包含了用于测试 `libword_list.dll` 的主要功能的主程序。
3. `word_list.h`：定义了 `libword_list.dll` 的接口和相关导入导出宏。
4. `readWordFromFile.cpp`：实现从文件中读取单词的功能。

下面我们详细分析这几个文件的作用和如何进行测试：

##### CMakeLists.txt

​		这个文件定义了如何构建测试目标。它首先设置了测试目标名称为 `wordlist_test`，然后添加了所有相关的源文件。之后，它创建一个可执行文件目标，并设置其输出目录。接下来，包含了头文件目录，并链接了 `libword_list.dll` 动态库。最后，它启用了 C++11 标准。

##### test_wordlist.cpp

​		这个文件包含了测试的主程序。主要步骤如下：

1. 输出 "test start..." 提示测试开始。
2. 调用 `readWordsFromFile` 函数从 "test.txt" 文件中读取单词，保存在字符串数组 `strings` 中。
3. 调用待测试的函数，将结果保存在 `result` 变量中。
4. 输出 "test end!" 提示测试结束。

##### word_list.h

​		这个文件定义了 `libword_list.dll` 的接口。它首先根据编译器设置导入导出宏，然后包含了所有需要的头文件和命名空间。接着，它声明了 `libword_list.dll` 中导出的函数，如 `gen_chains_all`, `gen_chain_word`, `gen_chain_char`。

#### 测试架构

我们采用`googletest`工具对我们的代码进行测试，以下是实现思路：

1. 在CMakeLists.txt中，包含googletest的头文件和库文件路径。

   ```
   bashCopy codeinclude_directories(${CMAKE_SOURCE_DIR}/lib/googletest/include)
   link_directories(${CMAKE_SOURCE_DIR}/lib/googletest/cmake-build-debug/lib)
   ```

2. 在CMakeLists.txt中，添加`test`子目录，这将包含测试代码。

   ```
   scssCopy code
   ADD_SUBDIRECTORY(test)
   ```

3. 在`test`目录中，创建测试源文件`test_wordlist.cpp`和头文件`word_list.h`。在`test_wordlist.cpp`中，编写针对项目功能的测试用例。

4. 在CMakeLists.txt中，添加测试源文件到一个变量中。

   ```
   bashCopy codeset(TEST_SOURCES
       test/test_wordlist.cpp
       test/word_list.h
   )
   ```

5. 在CMakeLists.txt中，添加一个可执行的测试目标`word_list_test`，并将测试源文件作为参数。

   ```
   scssCopy code
   add_executable(word_list_test ./test/test_wordlist.cpp)
   ```

6. 链接项目中的库以及`googletest`的库到测试目标`word_list_test`。

   ```
   scssCopy codetarget_link_libraries(word_list_test MyLibrary)
   target_link_libraries(word_list_test gtest gtest_main)
   ```

7. 编译项目时，将同时编译测试代码。在编译完成后，可以运行`word_list_test`可执行文件，以运行针对项目功能的测试用例。

#### 测试用例

我们使用两种方式产生测试用例，并且将测试样例分为有环和无环，以下是部分测试样例：

1.手搓无环样例：

```
"uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuv","uuuuv","uuv","vw","wx","xy","yz","yy","aaaaab","aab","bbbbbbc","cccg","cccd","dg","yz","yy","aaaaab","aab","bbbbbbc","cccg","cccd","dg","yz","yy","aaaaab","aab","bbbbbbc","cccg","cccd","dg","gggggj","hi","ij","jm","mn","opq","opq","opq","opq","opq","op","oo","bb"
```

2.自动生成无环样例：

```
"mampikdfgfdazsi", "nyqaffouyi", "ftcmodfvab", "ysadyjbqjn", "ytofdatiic", "ucbbpgldjt", "rpvcjfifda","yzaspfqqhl", "rjzbyezhri", "tcbvwvlcsdfdfdfsdfsdfghjksdfghjklsdfghjklmk", "rmobyrfzad", "cgbuxirxka", "qzkfztenzl", "xnmwvbptte","kwnjsdfsrpwmi", "kchpcaamde", "vvwrkckcyg", "xywwslplun", "xnghndhace", "seeqprvqao", "wtbrjfujid","zftjdfdzcbwva", "xjsbrklhod", "lgmpnndykj", "oselbndknc", "pjsxolpfwi", "karyajsnmi", "tyxrtjsfgr","womlfmmbtu", "qtqajuhmqa", "zmdojgvkbc", "lddwlzpisb", "zwvdqcdjqw", "xbppktxwaw", "wlhjmusfzk","wgktdyjmjg", "jbwmsdfejcjkb", "udksdfoollyxk", "rfipdfuqfj", "ztwqjdqzgm", "udmjcehedc", "tysjpkyczo","vdbntdfrba", "spbcnyibpd", "xqldhshojo", "ketesrwljj", "sjazrwsuah", "qzxaqeqwxp", "kscdthxkpb", "ztmsdfprhtmks", "ynvqpuggfd", "ryynaozysl", "miwhzzvxof", "nblgqayowf", "thqsrqhcqa", "eiiucfhbyd","uovoiyglec", "iuufqbjsdfpzg", "sgpagbnvmk", "qvhumtzvqg", "ydsvqlhmrm", "lgfopmnkma", "qvdemjdlkn","ecrcrbtfia", "zfvdfgyhahth", "nisdfswonbcbf", "pqzygcqhif", "zhkppannvn", "ollnjzjssj", "jpgkdxrtcc","zezjjmfrsdzi", "zskilnqcfi", "niimmanhei", "wucmghusku", "odsoyfdrwa", "pobfgkkmti", "zmnvvgfnvo","mewwesdfylnjg", "yanypvwemb", "ytgysdfypxpcn", "rkquecuruj", "kxigidiwuj", "wquaychqea", "tlclyiknac","yxefklbnys", "ffwiyfrgpb", "xfnvbqpsdftjutcr", "ttwfzntpzl", "nxvszgwlbj", "zonaraujbc", "tihbhnfrbb", "tnjaegslsc", "ruskfsdfubaaq"
```

3.手搓有环样例：

```
"uuuuv","vw","wx","xy","yz","yy","aaaaab","aab","bbbbbbc","cccg","cccd","dg","gggggj","hi","ij","jm","mn","opq","op","oo","bb","za","ga","gb","sb","lj","ssl","somethings"
```

考虑到自动生成无环样例较为困难，`python`源码放置在项目`test`文件夹中。

#### 测试覆盖率

以下是核心代码的测试覆盖率，因为编译器会插入一些分支代码防止空指针访问等错误行为，这些分支一执行程序就`shut down`了，但是`gtest`在汇编的层面认不出来这些代码是我们的还是编译器加的。因此，`func.cpp`和`task1.cpp`两个文件的分支覆盖率不是很理想。尽管如此，我们的分支覆盖率平均也是远超`90%`，代码覆盖率接近`100%`。

![image_2](images\image_2.png)

### 10 异常处理

​	`unknown_parameter` 异常类：用于处理存在未知参数的情况。当用户输入的参数中存在一个或多个未知的参数时，该异常会被抛出。

​	单元测试样例：

```
# 输入参数
-n input.txt -m -a

# 期望结果
xxx\word_list.exe: unknown option -- m
xxx\word_list.exe: unknown option -- a
There are unknown parameters.
```

​	`none_parameter` 异常类：用于处理没有参数的情况。当用户没有输入任何参数时，该异常会被抛出。

​	单元测试样例：

```
# 输入参数（空）

# 期望结果
There are no parameters.
```

​	`incompatible_parameter` 异常类：用于处理不兼容的参数。当用户输入的参数不兼容时，例如同时包括`-n`和`-w`参数时，该异常会被抛出。

​	单元测试样例：

```
# 输入参数
-n input.txt -w input.txt

# 期望结果
The parameters are not compatible.
```

​	`single_additional_parameter` 异常类：用于处理只包含附加参数的情况。当用户只输入一个或多个附加参数，而没有输入功能性参数时，该异常会被抛出。

​	单元测试样例：

```
# 输入参数
-h a -t m

# 期望结果
Additional parameters cannot exist alone.
```

​	`repeat_parameter` 异常类：用于处理重复参数的情况。当用户输入了重复的参数时，该异常会被抛出。

​	单元测试样例：

```
# 输入参数
-n input.txt -rr

# 期望结果
Duplicate parameters.
```

​	`format_filename` 异常类：用于处理文件名格式不正确的情况。当用户输入的文件名格式不正确时（例如输入文件不是以`.txt`结尾），该异常会被抛出。

​	单元测试样例：

```
# 输入参数
-n input.docx

# 期望结果
The filename format is incorrect.
```

​	`none_exist_file` 异常类：用于处理文件不存在的情况。当用户输入的文件名不存在时，该异常会被抛出。

​	单元测试样例：

```
# 输入参数（文件不存在）
-n input.txt

# 期望结果
The file does not exist.
```

​	`format_parameter_content` 异常类：用于处理附加参数内容格式不正确的情况。当用户输入的附加参数内容不符合规定的格式时（如`-h`参数内容包括多个字母），该异常会被抛出。

​	单元测试样例：

```
# 输入参数（文件不存在）
-n input.txt -h ab

# 期望结果
Additional parameter content can only be one letter.
```

### 11 界面模块的详细设计过程

​		我们使用`Python`语言中的`Tkinter`库作为基础组件库，并使用`Ttkbootstrap`库进行美化设计。我们将界面分成几个基础功能区，使用`Frame`组件，使其看起来简洁突出。我们使用`Tkinter`中的`Text`和`FileDialog`功能来获取数据并实现数据的导入，并且使用`Toplevel`组件来打印输出结果，并将结果保存。整个过程中，我们注重设计的细节和用户体验，确保整个应用程序的流畅性和易用性。

### 12 界面模块与计算模块的对接

我们采用了`ctypes`库来导入我们的计算模块，为了解决数据的传入传出问题，我们在原先`api`的基础上对其进行了进一步包装。

- Python端

  我们基于`ctypes.Structure`类，定义了两个结构体来接受计算模块的返回值。

  ```python
  from ctypes import *
  
  class RetTwoDim(Structure):
      _fields_ = [
          ('dataList', (c_char_p * 10000) * 10000),
          ('dataNumOne', c_int * 10000),
          ('dataNumTwo', c_int)
      ]
  
  
  class RetOneDim(Structure):
      _fields_ = [
          ('dataList', c_char_p * 10000),
          ('dataNum', c_int)
      ]
  ```

  之后，我们通过`ctypes.windll`方法导入动态链接库，并调用我们实现的`api`接口函数。

  ```
  from ctypes import *
  
  libc = windll.LoadLibrary("xxx")
  func = libc.xxx
  ```

- C++端

  由于C++中`vector`的问题，我们在原先`api`的基础上再次进行了包装，创建了`api_cpy.cpp`文件。（下面是部分内容）

  结构体定义：

  ```c++
  struct cpyRetOneDim {
      const char *dataList[10000];
      int dataNum;
  };
  
  struct cpyRetTwoDim {
      const char *dataList[10000][10000];
      int dataNumOne[10000];
      int dataNumTwo;
  };
  ```

  `api`函数：

  ```c++
  extern "C" __declspec(dllexport)
  cpyRetTwoDim *gen_chains_all_cpy(char **words, int len) {
      vector<vector<string>> result;
      auto *retResult = (cpyRetTwoDim *) malloc(sizeof(cpyRetTwoDim));
      int size = gen_chains_all(words, len, result);
      retResult->dataNumTwo = size;
      for (int i = 0; i < size; i++) {
          retResult->dataNumOne[i] = result[i].size();
          for (int j = 0; j < result[i].size(); j++) {
              retResult->dataList[i][j] = result[i][j].c_str();
          }
      }
      return retResult;
  }
  ```

实现界面：

![image-20230318171536684](images\image-20230318171536684.png)

![image-20230318171511504](images\image-20230318171511504.png)



### 13 描述结对的过程

1. 讨论需求和目标：我们首先在微信中讨论了任务的要求和目标，以确保彼此理解任务的重点和细节。
   ![image-20230314113350974](images\image-20230314113350974.png)

   

2. 设计和规划：在确定任务和工具后，我们在微信上共同制定一个开发计划和任务分工，以确保我们能够在预定时间内完成任务。我们一起讨论解决问题的方法和技术，并设计相应的程序结构和算法。
   ![image-20230314113452633](images\image-20230314113452633.png)

3. 开始编码：我们编写代码时，编码的同学输入代码。而另一个同学监督代码的编写并且复核代码，帮助发现潜在的错误并提出改进意见。在编码的过程中，我们一直保持良好的沟通，以确保彼此的理解和协作。
   ![image-20230314113615109](images\image-20230314113615109.png)

4. 进行测试和调试：当代码编写完毕后，我们进行了测试和调试，以确保程序能够正常工作。我们共同讨论测试方案和测试用例，并一起运行测试程序。

5. 代码审查和改进：在测试和调试之后，我们共同检查代码，找出可能存在的错误和问题，并提出了改进意见。同时，我们还进行了代码重构和优化，以提高程序的质量和性能。

### 14 结对编程的优点和缺点

优点：

1. 提高了代码的质量：结对编程可以减少错误和缺陷，因为两个人会互相检查彼此的代码，并及时纠正错误。
2. 加速了开发速度：结对编程可以促进团队成员之间的交流和协作，使开发速度更快。
3. 提高了团队成员的技能：结对编程可以相互学习，提高技能水平。

缺点：

1. 双方必须达成一致：如果两个人的编程风格和方法不同，他们可能需要花费更多的时间来协调，这可能会导致开发速度降低。

### 15 界面模块，测试模块和核心模块的松耦合【附加题】

我们也和其他组进行了模块交换，由于我们两个小组已经规定好了调用接口，故在测试过程中我们在代码方面基本没有问题。

但是，由于我们组采用的是`python`的`ctypes`库，在实际调用其他组的核心模块时出现了`Module Not Found`的报错。经过`debug`，发现是在`windows`下缺少部分动态链接库的问题，添加后，发现基本没有问题。下面这是输出的一个例子：

![image-20230319184605317](images\image-20230319184605317.png)

附合作小组：周奕龙（20373892）林子杰（20373980）
