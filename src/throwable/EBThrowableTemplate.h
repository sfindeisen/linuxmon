/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_EBThrowableTemplate_H_
#define _linuxmon_throwable_EBThrowableTemplate_H_

#include <typeinfo>

#include "EBAbstractThrowable.h"

namespace linuxmon {

template <class T> class EBThrowableTemplate : public linuxmon::EBAbstractThrowable, public T {
    public:
        EBThrowableTemplate(const TString& s);
        EBThrowableTemplate(const char *s);
        // EBThrowableTemplate(const EBThrowableTemplate& another);
        virtual ~EBThrowableTemplate() throw();
        // virtual EBThrowableTemplate& operator=(const EBThrowableTemplate& another);

        virtual TString getName() const =0;
        virtual TString asString() const;

        const TString& getMessage      () const;
        const TString& getFileName     () const;
        const TString& getFunctionName () const;
        int            getLineNumber   () const;

        void setFileName    (const TString& s);
        void setFunctionName(const TString& s);
        void setLineNumber  (const int i);

    private:
        TString message;
        TString fileName;
        TString funcName;
        int     lineNumber;
};

template <class T> EBThrowableTemplate<T>::EBThrowableTemplate(const char *s)
    : EBAbstractThrowable(), T(s), message(s), fileName(""), funcName(""), lineNumber(0)
{
}

template <class T> EBThrowableTemplate<T>::EBThrowableTemplate(const TString& s)
    : EBAbstractThrowable(), T(s), message(s), fileName(""), funcName(""), lineNumber(0)
{
}

template <class T> EBThrowableTemplate<T>::~EBThrowableTemplate() throw() {
}

template <class T> TString EBThrowableTemplate<T>::asString() const {
    TStringStream ss;
    ss << "EBThrowableTemplate<" << (typeid(T).name()) << "> " << getName() << " at " << getFileName() << ":" << getLineNumber() << " " << getFunctionName() << ": " << getMessage();
    return ss.str();
}

template <class T> const TString& EBThrowableTemplate<T>::getMessage() const {
    return message;
}
template <class T> const TString& EBThrowableTemplate<T>::getFileName() const {
    return fileName;
}
template <class T> const TString& EBThrowableTemplate<T>::getFunctionName() const {
    return funcName;
}
template <class T> int EBThrowableTemplate<T>::getLineNumber() const {
    return lineNumber;
}
template <class T> void EBThrowableTemplate<T>::setFileName(const TString& s) {
    this->fileName = s;
}
template <class T> void EBThrowableTemplate<T>::setFunctionName(const TString& s) {
    this->funcName = s;
}
template <class T> void EBThrowableTemplate<T>::setLineNumber(const int i) {
    this->lineNumber = i;
}

};

#endif
