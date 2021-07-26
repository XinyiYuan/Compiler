shopt -s expand_aliases
alias antlr4='java -Xmx500M -cp "/home/comiler7/lib/antlr-4.8-complete.jar:$CLASSPATH" org.antlr.v4.Tool'

antlr4 ./grammar/CACT.g4
cd build
cmake ..
make