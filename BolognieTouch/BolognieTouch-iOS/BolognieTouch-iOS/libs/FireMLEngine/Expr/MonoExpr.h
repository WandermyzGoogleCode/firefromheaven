//
//  MonoExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_MonoExpr_h
#define BolognieTouch_iOS_MonoExpr_h

#include "RightValueExpr.h" 

namespace FireMLEngine {
    class MonoExpr : public RightValueExpr {
    private:
        Expression* op;
        
    public:
        MonoExpr() : op(NULL) { }
        virtual ~MonoExpr() {
            if (op != NULL) {
                delete op;
            }
        }
        
        template <class T>
        T* createOp() {
            T* newOp = new T();
            op = newOp;
            return newOp;
        }
        
        inline Expression* getOp() { return op; }
        
        virtual void accept(IExprVisitor* visitor) = 0;
    };
}

#endif
