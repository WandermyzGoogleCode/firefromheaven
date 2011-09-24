﻿using System;
using System.Collections.Generic;
using System.Text;

namespace FireEngine.FireMLEngine.AST
{
    [Serializable]
    public class PlotDef : Definition
    {

        public List<Statement> Content
        {
            get;
            set;
        }


        internal override void Accept(IASTVisitor visitor, params object[] args)
        {
            visitor.Visit(this, args);
        }

        internal override ASTNode[] Children
        {
            get
            {
                return Content.ToArray();
            }
        }
    }
}
