#!/bin/bash
shopt -s globstar

INPUT_SOURCE_FILE="$1"
[ -z "$INPUT_SOURCE_FILE" ] && INPUT_SOURCE_FILE="main.cpp"
INPUT_HEADER_FILES="${@:2}"
[ -z "$INPUT_HEADER_FILES" ] && INPUT_HEADER_FILES="$(ls **/*.h)"

## system includes ##
system_includes="$(perl -ne 'print if /#include\s*<\w+>/g' $INPUT_SOURCE_FILE $INPUT_HEADER_FILES \
    | sort \
    | uniq \
)"

## evaluated main function ##
comp_cmd="$(perl -ne 'print if s/\/\/\s?g\+\+ (.*)/g++ -E $1/' $INPUT_SOURCE_FILE)"
eval_main_fn="$($comp_cmd \
    | tail -n1000 \
    | perl -e 'my $s = do { local $/; <> }; $s =~ /(int main\(.*)/s && print $1' \
)"

## concatenate final out.cpp file ##
out_cpp_comp_cmd="$(perl -pe 's/ -E//' <<< "$comp_cmd" \
    | perl -pe 's/ -I \S+//' \
    | SRC="$INPUT_SOURCE_FILE" perl -pe 's/\Q$ENV{SRC}\E/out.cpp/' \
)"
cat <(cat <<< "$system_includes") \
    <(echo) \
    <(echo "// $out_cpp_comp_cmd") \
    <(cat <<< "$eval_main_fn")
