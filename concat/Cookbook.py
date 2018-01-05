#* Imports
import pycook.recipes.cpp as r_cpp
import pycook.recipes.java as r_java

#* Recipes
def cpp(recipe):
    return r_cpp.compile_and_run("cpp/concat.cc")

def sbcl(recipe):
    return ["sbcl --script sbcl/concat.lisp"]

def python(recipe):
    return ["python3 python/concat.py"]

def java(recipe):
    return r_java.compile_and_run("java/Concat.java")

def clojure(recipe):
    return ["clojure -e '(load-file \"clojure/concat.clj\")'"]

def clojure_1(recipe):
    return ["cd clojure",
            "clojure -e '(load-file \"concat1.clj\")'"]

def all(recipe):
    return (
        cpp(recipe) +
        sbcl(recipe) +
        python(recipe) +
        java(recipe) +
        clojure(recipe) +
        clojure_1(recipe))
