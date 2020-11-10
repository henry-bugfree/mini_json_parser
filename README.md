此分析器仅针对文件syntax.txt中给出的文法，它是JSON语言的一个子集，下文简称该文法。

json_scanner.cpp是针对该文法的词法分析器。  
json_parser.cpp是针对该文法的语法分析器，使用递归下降法(recursive decent)。  
json.txt提供了一个符合该文法的测试用例。  
syntax.txt说明了该文法(G1)及其消除左递归和提取公共左因子后的形式(G1')。  

<---------------------------------above is ver1.1----------------------------------->  

对可分析的文法做了扩充,增加了array()等文法,使其更接近于JSON文法。  
现在的syntax.txt摘录自[JSON网站](https://www.json.org/json-en.html)提供的文法。  
该分析器目前不具备分析其完整文法的能力。  
