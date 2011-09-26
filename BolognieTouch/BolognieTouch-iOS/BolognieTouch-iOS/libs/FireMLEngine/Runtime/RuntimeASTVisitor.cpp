//
//  RuntimeASTVisitor.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "RuntimeASTVisitor.h"
#include "RuntimeKernel.h"
#include "DialogStmt.h"
#include "BackgroundStmt.h"
#include "ActorStmt.h"
using namespace FireMLEngine;

RuntimeASTVisitor::RuntimeASTVisitor(RuntimeKernel* kernel) : kernel(kernel) {
    
}

void RuntimeASTVisitor::visit(FireMLRoot* root) {
    root->mainPlot.accept(this);
}

void RuntimeASTVisitor::visit(ActionLayerDef* actionLayerDef) { }
void RuntimeASTVisitor::visit(FunctionDef* functionDef) { }

void RuntimeASTVisitor::visit(PlotDef* plotDef) {
    //TODO: scope stack open
    kernel->getRuntimeData()->getInstructionStack().push(InstructionStack::CLOSE_LOCAL_SCOPE_FLAG);
    kernel->getRuntimeData()->getInstructionStack().push(plotDef->content);
    kernel->next();
}

void RuntimeASTVisitor::visit(ContinueStmt* continueStmt) { }
void RuntimeASTVisitor::visit(FunctionCallStmt* funcCallStmt) { }
void RuntimeASTVisitor::visit(MusicStmt* musicStmt) { }
void RuntimeASTVisitor::visit(MusicStopStmt* musicStopStmt) { }
void RuntimeASTVisitor::visit(MusicVolStmt* musicVolStmt) { }
void RuntimeASTVisitor::visit(SwitchStmt* switchStmt) { }
void RuntimeASTVisitor::visit(SelectStmt* selectStmt) { }

void RuntimeASTVisitor::visit(ActorStmt* actorStmt) {
    kernel->getRuntimeData()->currentActorName = actorStmt->name;
    kernel->getRuntimeData()->currentActorAvatar = actorStmt->avatar; 
    //TODO: asset, layer
    
    kernel->behave(kernel->getFuncCaller()->actor(actorStmt->img, actorStmt->layer, actorStmt->position));
}

void RuntimeASTVisitor::visit(DialogStmt* dialogStmt) {
    kernel->behave(kernel->getFuncCaller()->dialog(dialogStmt->text, kernel->getRuntimeData()->currentActorName));
    //TODO: varRefProcessor.replace
}

void RuntimeASTVisitor::visit(IfStmt* ifStmt) { }
void RuntimeASTVisitor::visit(LoopStmt* loopStmt) { }

void RuntimeASTVisitor::visit(BackgroundStmt* backgroundStmt) { 
    kernel->behave(kernel->getFuncCaller()->background(backgroundStmt->img));
    //TODO: asset
}

void RuntimeASTVisitor::visit(EchoStmt* echoStmt) { }
void RuntimeASTVisitor::visit(IncludeStmt* includeStmt) { }
void RuntimeASTVisitor::visit(BreakStmt* breakStmt) { }
void RuntimeASTVisitor::visit(ExpressionStmt* expressionStmt) { }
void RuntimeASTVisitor::visit(ReturnStmt* returnStmt) { }

void RuntimeASTVisitor::visit(ParameterDef* parameterDef) { }
void RuntimeASTVisitor::visit(SelectOption* selectOption) { }
void RuntimeASTVisitor::visit(SwitchCase* switchCase) { }
void RuntimeASTVisitor::visit(IfBlock* ifBlock) { }

void RuntimeASTVisitor::visit(DataStmt* dataStmt) { }
void RuntimeASTVisitor::visit(AssetDef* assetDef) { }
