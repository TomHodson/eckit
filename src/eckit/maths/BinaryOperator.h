/*
 * (C) Copyright 1996-2013 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/// @file BinaryOperator.h
/// @author Baudouin Raoult
/// @author Tiago Quintino
/// @date November 2013

#ifndef eckit_maths_BinaryFunc_h
#define eckit_maths_BinaryFunc_h

#include <functional>

#include "eckit/maths/Function.h"
#include "eckit/maths/Undef.h"


namespace eckit {
namespace maths {

//--------------------------------------------------------------------------------------------

/// Generates a expressions
template <class T>
class BinaryOperator : public Function  {
public:

    /// generator of of this expression type
    static ExpPtr make( ExpPtr p0, ExpPtr p1 )
    {
        args_t args;
        args.push_back( p0 );
        args.push_back( p1 );
        return ExpPtr( new BinaryOperator<T>(args) );
    }

    static std::string className();

    BinaryOperator( const args_t& args );

    virtual std::string typeName() const;

    virtual std::string returnSignature() const;

    /// Applies an implementation of the binary operator
    /// T is the operator type ( Add, Sub, etc ... )
    /// U is the left operand type ( Scalar, Vector, ... )
    /// V is the right operand type ( Scalar, Vector, ... )
    /// I is the implementation type
    template < class U, class V, class I >
    class Computer {
    public:

        /// @todo adapt this to regist multiple implmentations ( class I )

        /// The signature that this computer implements
        static std::string sig();

        /// Constructor regists the implementation of this computer in the Function::dispatcher()
        Computer();

        /// Computes the expression with the passed arguments
        static ExpPtr compute( const args_t& p );
    };

    virtual void asCode( std::ostream& o ) const;
};

//--------------------------------------------------------------------------------------------

typedef std::multiplies<scalar_t>  Prod;
typedef std::divides<scalar_t>     Div;
typedef std::plus<scalar_t>        Add;
typedef std::minus<scalar_t>       Sub;
typedef std::modulus<scalar_t>     Mod;

//--------------------------------------------------------------------------------------------

// version with stand alone functions

ExpPtr prod( ExpPtr l = undef(), ExpPtr r = undef() );
ExpPtr div( ExpPtr l = undef(), ExpPtr r = undef() );
ExpPtr add( ExpPtr l = undef(), ExpPtr r = undef() );
ExpPtr sub( ExpPtr l = undef(), ExpPtr r = undef() );
ExpPtr mod( ExpPtr l = undef(), ExpPtr r = undef() );
//ExpPtr mod( Expression& l, Expression& r );


//--------------------------------------------------------------------------------------------

} // namespace maths
} // namespace eckit

#endif
