此解析器仅针对文件syntax.txt中给出的文法，它是JSON语言的一个子集，下文简称该文法。

json_scanner.cpp是针对该文法的词法分析器。
json_parser.cpp是针对该文法的语法分析器，使用递归下降法(recursive decent)。
json.txt提供了一个符合该文法的测试用例。
syntax.txt说明了该文法(G1)及其消除左递归和提取公共左因子后的形式(G1')。