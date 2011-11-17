
/*
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!
 */

#ifndef __dbusxx__echo_server_glue_h__ADAPTOR_MARSHAL_H
#define __dbusxx__echo_server_glue_h__ADAPTOR_MARSHAL_H

#include <dbus-c++/dbus.h>
#include <cassert>

namespace org {
namespace freedesktop {
namespace DBus {

class EchoDemo_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    EchoDemo_adaptor()
    : ::DBus::InterfaceAdaptor("org.freedesktop.DBus.EchoDemo")
    {
        register_method(EchoDemo_adaptor, Random, _Random_stub);
        register_method(EchoDemo_adaptor, Hello, _Hello_stub);
        register_method(EchoDemo_adaptor, Echo, _Echo_stub);
        register_method(EchoDemo_adaptor, Cat, _Cat_stub);
        register_method(EchoDemo_adaptor, Sum, _Sum_stub);
        register_method(EchoDemo_adaptor, Info, _Info_stub);
    }

    ::DBus::IntrospectedInterface *const introspect() const 
    {
        static ::DBus::IntrospectedArgument Random_args[] = 
        {
            { "version", "i", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Hello_args[] = 
        {
            { "name", "s", true },
            { "greeting", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Echo_args[] = 
        {
            { "input", "v", true },
            { "output", "v", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Cat_args[] = 
        {
            { "file", "s", true },
            { "stream", "ay", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Sum_args[] = 
        {
            { "ints", "ai", true },
            { 0, "i", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Info_args[] = 
        {
            { "info", "a{ss}", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Echoed_args[] = 
        {
            { "value", "v", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod EchoDemo_adaptor_methods[] = 
        {
            { "Random", Random_args },
            { "Hello", Hello_args },
            { "Echo", Echo_args },
            { "Cat", Cat_args },
            { "Sum", Sum_args },
            { "Info", Info_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod EchoDemo_adaptor_signals[] = 
        {
            { "Echoed", Echoed_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty EchoDemo_adaptor_properties[] = 
        {
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface EchoDemo_adaptor_interface = 
        {
            "org.freedesktop.DBus.EchoDemo",
            EchoDemo_adaptor_methods,
            EchoDemo_adaptor_signals,
            EchoDemo_adaptor_properties
        };
        return &EchoDemo_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual int32_t Random() = 0;
    virtual std::string Hello(const std::string& name) = 0;
    virtual ::DBus::Variant Echo(const ::DBus::Variant& input) = 0;
    virtual std::vector< uint8_t > Cat(const std::string& file) = 0;
    virtual int32_t Sum(const std::vector< int32_t >& ints) = 0;
    virtual std::map< std::string, std::string > Info() = 0;

public:

    /* signal emitters for this interface
     */
    void Echoed(const ::DBus::Variant& arg1)
    {
        ::DBus::SignalMessage sig("Echoed");
        ::DBus::MessageIter wi = sig.writer();
        wi << arg1;
        emit_signal(sig);
    }

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _Random_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        int32_t argout1 = Random();
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _Hello_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        std::string argout1 = Hello(argin1);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _Echo_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        ::DBus::Variant argin1; ri >> argin1;
        ::DBus::Variant argout1 = Echo(argin1);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _Cat_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        std::vector< uint8_t > argout1 = Cat(argin1);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _Sum_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::vector< int32_t > argin1; ri >> argin1;
        int32_t argout1 = Sum(argin1);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _Info_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::map< std::string, std::string > argout1 = Info();
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
};

} } } 
#endif //__dbusxx__echo_server_glue_h__ADAPTOR_MARSHAL_H
