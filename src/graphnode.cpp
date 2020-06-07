#include "graphedge.h"
#include "graphnode.h"

#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.emplace_back(std::move(edge));
    // _childEdges.push_back(std::move(edge));
    // _childEdges.push_back(edge);
}

//// STUDENT CODE
////

void GraphNode::MoveChatbotHere(ChatBot chatbot)
// void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = std::move(chatbot);
    std::cout << "chatBot move semantic" << std::endl;
    // _chatBot = chatbot;
    _chatBot.SetCurrentNode(this);
    std::cout << "chatBot set current node" << std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}