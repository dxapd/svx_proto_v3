#include "solver/final_tree.h"

#include "solver/final_box.h"

Solver::FinalTree::FinalTree() : finalBoxes() { rootBoxHandle = -1; }

void Solver::FinalTree::Reset() { finalBoxes.clear(); }

Solver::FinalBoxHandle Solver::FinalTree::InitRoot(Solver::FinalBox finalBox) {
    if (finalBoxes.size() > 0) Solver::FinalTree::Reset();
    finalBoxes.emplace_back(finalBox);
    rootBoxHandle = 0;
    Solver::FinalTree::GetBox(rootBoxHandle).handle = rootBoxHandle;

    return rootBoxHandle;
}

Solver::FinalBoxHandle Solver::FinalTree::AddBox(
    Solver::FinalBox finalBox,
    Solver::FinalBoxHandle parentHandle) {
    finalBoxes.emplace_back(finalBox);
    Solver::FinalBoxHandle handle = finalBoxes.size() - 1;

    Solver::FinalTree::GetBox(handle).handle = handle;
    Solver::FinalTree::GetBox(parentHandle).children.emplace_back(handle);

    return handle;
}

Solver::FinalBox& Solver::FinalTree::GetBox(
    Solver::FinalBoxHandle finalBoxHandle) {
    return finalBoxes[finalBoxHandle];
}

Solver::FinalBoxHandle Solver::FinalTree::GetRootBox() { return rootBoxHandle; }

size_t Solver::FinalTree::Count() const { return finalBoxes.size(); }