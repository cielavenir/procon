#ifndef STREAM_FROMFILE_H
#define STREAM_FROMFILE_H

#include <cstdio>

#if defined(STREAM_GCC)
	//libstdc++ is required
	#include <ext/stdio_filebuf.h>
	class streambuf_fromfile_out:
	public __gnu_cxx::stdio_filebuf<char>{
		public:
		streambuf_fromfile_out(FILE *f):
		__gnu_cxx::stdio_filebuf<char>(
			fileno(f),std::ios_base::out
		){}
		streambuf_fromfile_out(int fd):
		__gnu_cxx::stdio_filebuf<char>(
			fd,std::ios_base::out
		){}
	};
	class streambuf_fromfile_in:
	public __gnu_cxx::stdio_filebuf<char>{
		public:
		streambuf_fromfile_in(FILE *f):
		__gnu_cxx::stdio_filebuf<char>(
			fileno(f),std::ios_base::in
		){}
		streambuf_fromfile_in(int fd):
		__gnu_cxx::stdio_filebuf<char>(
			fd,std::ios_base::in
		){}
	};
#elif defined(STREAM_BOOST)
	//libboost_iostreams is required
	#include <boost/iostreams/device/file_descriptor.hpp>
	#include <boost/iostreams/stream.hpp>
	class streambuf_fromfile_out:
	public boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_sink>{
		public:
		streambuf_fromfile_out(FILE *f):
		boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_sink>(
			fileno(f),boost::iostreams::never_close_handle
		){}
		streambuf_fromfile_out(int fd):
		boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_sink>(
			fd,boost::iostreams::never_close_handle
		){}
	};
	class streambuf_fromfile_in:
	public boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source>{
		public:
		streambuf_fromfile_in(FILE *f):
		boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source>(
			fileno(f),boost::iostreams::never_close_handle
		){}
		streambuf_fromfile_in(int fd):
		boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source>(
			fd,boost::iostreams::never_close_handle
		){}
	};
#elif defined(STREAM_PORTABLE)
/* The following code declares classes to read from and write to
 * file descriptore or file handles.
 *
 * See
 *      http://www.josuttis.com/cppcode
 * for details and the latest version.
 *
 * - open:
 *      - integrating BUFSIZ on some systems?
 *      - optimized reading of multiple characters
 *      - stream for reading AND writing
 *      - i18n
 *
 * (C) Copyright Nicolai M. Josuttis 2001.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 *
 * Version: Jul 28, 2002
 * History:
 *  Jul 28, 2002: bugfix memcpy() => memmove()
 *                fdinbuf::underflow(): cast for return statements
 *  Aug 05, 2001: first public version
 */

#include <istream>
#include <ostream>
#include <streambuf>

// for memmove():
#include <cstring>

#if defined(_WIN32) || (!defined(__GNUC__) && !defined(__clang__))
	#include <io.h>
#else
	#include <unistd.h>
#endif

// BEGIN namespace BOOST
namespace boost {


/************************************************************
 * fdostream
 * - a stream that writes on a file descriptor
 ************************************************************/


class fdoutbuf : public std::streambuf {
  protected:
    int fd;    // file descriptor
  public:
    // constructor
    fdoutbuf (int _fd) : fd(_fd) {
    }
  protected:
    // write one character
    virtual int_type overflow (int_type c) {
        if (c != EOF) {
            char z = c;
            if (write (fd, &z, 1) != 1) {
                return EOF;
            }
        }
        return c;
    }
    // write multiple characters
    virtual
    std::streamsize xsputn (const char* s,
                            std::streamsize num) {
        return write(fd,s,num);
    }
};

class fdostream : public std::ostream {
  protected:
    fdoutbuf buf;
  public:
    fdostream (int fd) : std::ostream(0), buf(fd) {
        rdbuf(&buf);
    }
};


/************************************************************
 * fdistream
 * - a stream that reads on a file descriptor
 ************************************************************/

class fdinbuf : public std::streambuf {
  protected:
    int fd;    // file descriptor
  protected:
    /* data buffer:
     * - at most, pbSize characters in putback area plus
     * - at most, bufSize characters in ordinary read buffer
     */
    static const int pbSize = 4;        // size of putback area
    static const int bufSize = 1024;    // size of the data buffer
    char buffer[bufSize+pbSize];        // data buffer

  public:
    /* constructor
     * - initialize file descriptor
     * - initialize empty data buffer
     * - no putback area
     * => force underflow()
     */
    fdinbuf (int _fd) : fd(_fd) {
        setg (buffer+pbSize,     // beginning of putback area
              buffer+pbSize,     // read position
              buffer+pbSize);    // end position
    }

  protected:
    // insert new characters into the buffer
    virtual int_type underflow () {
#if defined(_WIN32) || (!defined(__GNUC__) && !defined(__clang__))
#else
        using std::memmove;
#endif

        // is read position before end of buffer?
        if (gptr() < egptr()) {
            return traits_type::to_int_type(*gptr());
        }

        /* process size of putback area
         * - use number of characters read
         * - but at most size of putback area
         */
        int numPutback;
        numPutback = gptr() - eback();
        if (numPutback > pbSize) {
            numPutback = pbSize;
        }

        /* copy up to pbSize characters previously read into
         * the putback area
         */
        memmove (buffer+(pbSize-numPutback), gptr()-numPutback,
                numPutback);

        // read at most bufSize new characters
        int num;
        num = read (fd, buffer+pbSize, bufSize);
        if (num <= 0) {
            // ERROR or EOF
            return EOF;
        }

        // reset buffer pointers
        setg (buffer+(pbSize-numPutback),   // beginning of putback area
              buffer+pbSize,                // read position
              buffer+pbSize+num);           // end of buffer

        // return next character
        return traits_type::to_int_type(*gptr());
    }
};

class fdistream : public std::istream {
  protected:
    fdinbuf buf;
  public:
    fdistream (int fd) : std::istream(0), buf(fd) {
        rdbuf(&buf);
    }
};

} // END namespace boost

class streambuf_fromfile_out:
public boost::fdoutbuf{
	public:
	streambuf_fromfile_out(FILE *f):
	boost::fdoutbuf(
		fileno(f)
	){}
	streambuf_fromfile_out(int fd):
	boost::fdoutbuf(
		fd
	){}
};
class streambuf_fromfile_in:
public boost::fdinbuf{
	public:
	streambuf_fromfile_in(FILE *f):
	boost::fdinbuf(
		fileno(f)
	){}
	streambuf_fromfile_in(int fd):
	boost::fdinbuf(
		fd
	){}
};
#else
	#error define one of: STREAM_GCC, STREAM_BOOST, STREAM_PORTABLE
#endif

#endif //included.