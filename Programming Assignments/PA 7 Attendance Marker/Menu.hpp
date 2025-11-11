#pragma once
#include "List.hpp"
#include "Data.hpp"

class Menu
{
public:
	Menu();
	~Menu();
	int getChoice() const;
	void setChoice(int const newChoice);
	List<Data> getList() const;
	void setList(List<Data> const newList);
	ListNode<Data>* getListNode() const;
	void setListNode(ListNode<Data>* newListNode);

	void ImportCourse(std::ifstream& inputStream);
	void LoadMaster(std::ifstream& masterInStream);
	void StoreMaster(std::ofstream& masterOutStream);
	void MarkAbsences();
	void GenerateReport();

private:
	int choice, limit;
	List<Data> list;
	ListNode<Data>* pCur;
};