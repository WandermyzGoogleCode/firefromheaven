﻿using System;
using System.Collections.Generic;
using System.Text;

namespace FireEngine.FireMLEngine.Expr
{
    [Serializable]
    //[System.Diagnostics.DebuggerDisplay("{this.GetType().Name},{FirstOp.ToString()}, {SecondOp.ToString()}")]
    abstract public class BinaryAlgoExpr : RightValueExpr
    {
        public Expression FirstOp
        {
            get;
            set;
        }

        public Expression SecondOp
        {
            get;
            set;
        }

        internal override abstract void Accept(IExprVisitor visitor, params object[] args);
    }
}
