#include "counterthread.h"

#include <Python.h>
#include <QDebug>

CounterThread::CounterThread(QObject *parent) : QThread(parent)
{

}

void CounterThread::run(){
    Py_Initialize();
    if(!Py_IsInitialized())
        {
            qDebug()<<"python init error";
            return ;
        }
    PyObject *pModule = PyImport_ImportModule("counter");
    if(!pModule)
       {
           qDebug()<<"module error";
           return;
       }
    PyObject * pFuncHello = PyObject_GetAttrString(pModule, "hello");
    if(!pFuncHello){
        return;
    }
}
