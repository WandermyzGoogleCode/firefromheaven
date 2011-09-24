﻿using System;
using System.Collections.Generic;
using System.Text;

namespace FireEngine.FireMLEngine.AST
{
    [Serializable]
    abstract public class Statement : ASTNode
    {
        internal override abstract void Accept(IASTVisitor visitor, params object[] args);
    }

}
