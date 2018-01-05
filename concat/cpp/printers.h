//* Includes
#ifndef PRINTERS_HH_
#define PRINTERS_HH_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <map>

//* Macros
#define TRACE(...) trace (__FILE__, __LINE__, __FUNCTION__, #__VA_ARGS__, __VA_ARGS__)

//* Functions
inline std::ostream& get_ostream() {
#ifdef TRACE_FILE
  static std::ofstream fout;
  if (!fout.is_open()) {
    fout.open(TRACE_FILE, std::ofstream::out
              // | std::ofstream::app
              );
  }
  return fout;
#else
  return std::cout;
#endif
}

template <typename T>
void trace(const char* file, int line, const char* func, const char* s, T x) {
  get_ostream() << file << ":" << line << ": info (" << func << ")\n"
                << s << ": " << x << std::endl;
}

inline std::ostream& trace_location(const char* file, int line, const char* func) {
  return get_ostream() << file << ":" << line << ": info (" << func << ")\n";
}

#ifndef TRACE_LOCATION
#define TRACE_LOCATION trace_location(__FILE__, __LINE__, __FUNCTION__)
#endif

class Newline
{
public:
  Newline()
      :_depth(0) {
  }
  Newline& operator ++() {
    _depth += 2;
    return *this;
  }

  Newline& operator --() {
    _depth -= 2;
    return *this;
  }

  int depth() const {
    return _depth;
  }
  static Newline& newline() {
    static Newline n;
    return n;
  }
private:
  int _depth;
};

inline std::ostream& operator << (std::ostream& out, Newline& n) {
  out << '\n';
  for (int i = 0; i < n.depth(); ++i)
    out << ' ';
  out << std::flush;
  return out;
}

template <typename T>
std::ostream& operator << (std::ostream &out, std::vector<T> &v) {
  Newline newline = Newline::newline();
  if (v.size () == 0)
    out << "[]";
  else {
    out << "[" << ++newline;
    for (unsigned int i = 0; i < v.size () - 1; ++i)
      out << v[i] << newline;
    out << v.back ();
    out << --newline << "]";
  }
  return out;
}

template <typename T>
std::ostream& operator << (std::ostream &out, const std::vector<T>& v) {
  out << static_cast<std::vector<T>>(v);
  return out;
}

template <typename K, typename V>
std::ostream& operator << (std::ostream& out, const std::map<K,V>& v) {
  Newline newline = Newline::newline();
  if (v.size() == 0)
    out << "{}";
  else {
    out << "{";
    ++newline;
    for (auto p : v)
      out << newline << p;
    out << --newline << "}";
    }
  return out;
}

template <typename A, typename B>
std::ostream& operator << (std::ostream &out, const std::pair<A,B>& p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T>
std::ostream& operator << (std::ostream &out, const std::queue<T>& q) {
  std::queue<T> Q = q;
  if (Q.size () == 0) {
    out << "q[]";
  } else {
    out << "q[";
    while (Q.size () > 1) {
      out << Q.front () << ", ";
      Q.pop ();
    }
    out << Q.front () << "]";
  }
  return out;
}

template <class T>
void print_array(std::ostream& out, T x) {
  Newline newline = Newline::newline();
  if (x.size == 0)
    out << "[]";
  else {
    out << "[" << ++newline;
    for (int i = 0; i < x.size - 1; ++i) {
      out << x.data[i] << newline;
    }
    out << x.data[x.size - 1];
    out << --newline << "]";
  }
}

//* Include guard end
#endif
