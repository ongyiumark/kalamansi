#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace Objects
{
    enum class Type
    {
        BOOLEAN,
        INTEGER,
        DOUBLE,
        STRING,
        LIST,
        FUNCTION,
        NONE
    };

    std::string type_to_string(Type type);

    class Object
    {
    public:
        virtual Type type() const = 0;
        virtual std::string to_string() const = 0;

        virtual Object* added_by(Object* other) const;
        virtual Object* subtracted_by(Object* other) const;
        virtual Object* multiplied_by(Object* other) const;
        virtual Object* divided_by(Object* other) const;
        virtual Object* modded_by(Object* other) const;
        virtual Object* powered_by(Object* other) const;
        virtual Object* accessed_by(Object* other) const;
        virtual Object* notted() const;
        virtual Object* less_than(Object* other) const;
        virtual Object* greater_than(Object* other) const;
        virtual Object* equals(Object* other) const;
        virtual Object* less_equals(Object* other) const;
        virtual Object* greater_equals(Object* other) const;
        virtual Object* not_equals(Object* other) const;
        virtual Object* and_with(Object* other) const;
        virtual Object* or_with(Object* other) const;
        virtual Object* xor_with(Object* other) const;
    };

    class Boolean final : public Object
    {
    private:
        bool _value;   
    public:
        Boolean(bool value);
        Type type() const;
        std::string to_string() const;
        bool get_value() const;

        Object* notted() const;
        Object* and_with(Object* other) const;
        Object* or_with(Object* other) const;
        Object* xor_with(Object* other) const;
        Object* equals(Object* other) const;
    };

    class Integer final : public Object
    {
    private:
        int _value;   
    public:
        Integer(int value);
        Type type() const;
        std::string to_string() const;
        int get_value() const;

        Object* added_by(Object* other) const;
        Object* subtracted_by(Object* other) const;
        Object* multiplied_by(Object* other) const;
        Object* divided_by(Object* other) const;
        Object* modded_by(Object* other) const;
        Object* powered_by(Object* other) const;
        Object* less_than(Object* other) const;
        Object* greater_than(Object* other) const;
        Object* equals(Object* other) const;
    };

    class Double final : public Object
    {
    private:
        double _value;   
    public:
        Double(double value);
        Type type() const;
        std::string to_string() const;
        double get_value() const;

        Object* added_by(Object* other) const;
        Object* subtracted_by(Object* other) const;
        Object* multiplied_by(Object* other) const;
        Object* divided_by(Object* other) const;
        Object* powered_by(Object* other) const;
        Object* less_than(Object* other) const;
        Object* greater_than(Object* other) const;
        Object* equals(Object* other) const;
    };

    class String final : public Object
    {
    private:
        std::string _value;   
    public:
        String(std::string value);
        
        Type type() const;
        std::string to_string() const;
        
        std::string get_value() const;
        int get_size() const;

        Object* added_by(Object* other) const;
        Object* multiplied_by(Object* other) const;
        Object* accessed_by(Object* other) const;
        Object* less_than(Object* other) const;
        Object* greater_than(Object* other) const;
        Object* equals(Object* other) const;
    };

    class List final : public Object
    {
    private:
        std::vector<Object*> _values;   
    public:
        List(std::vector<Object*>& values);
        
        Type type() const;
        std::string to_string() const;

        int get_size() const;
        Object* get_value(int i) const;
        std::vector<Object*> get_values() const;

        Object* added_by(Object* other) const;
        Object* accessed_by(Object* other) const;
        Object* equals(Object* other) const;
    };

    class Function final : public Object
    {
    private:
        std::string _name;
        std::vector<std::string> _argument_names;
        void* _body;
        bool _built_in;
    public:
        Function(std::string name, std::vector<std::string>& argument_names, void* body, bool built_in = false);
        
        Type type() const;
        std::string to_string() const;

        std::string get_name() const;

        int get_argument_size() const;
        std::string get_argument_name(int i) const;
        std::vector<std::string> get_argument_names() const;
        void* get_body() const;
        bool is_built_in() const;

        Object* equals(Object* other) const;
    };

    class None final : public Object
    {
    public:
        None();
        Type type() const;
        std::string to_string() const;

        Object* equals(Object* other) const;
    };
}





