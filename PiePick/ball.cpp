#include "pie.h"

ball::ball(bool isPie, int x,
	IMAGE* iunknown, IMAGE* iunknownx,
	IMAGE* ipie, IMAGE* ipiex,
	IMAGE* ibomb, IMAGE* ibombx,
	IMAGE* main_bg) {
	this->isPie = isPie;
	this->x = x;
	this->y = -50;
	this->w = iunknown->getwidth();
	this->h = iunknown->getheight();
	this->iunknown = iunknown;
	this->iunknownx = iunknownx;
	this->ipie = ipie;
	this->ipiex = ipiex;
	this->ibomb = ibomb;
	this->ibombx = ibombx;
	this->main_bg = main_bg;
	this->isCovered = true;
	this->lastShown = clock();
}
int ball::getX() {
	return x;
}
int ball::getY() {
	return y;
}
int ball::getW() {
	return w;
}
int ball::getH() {
	return h;
}
void ball::move(int speed) {
	y += speed;
	show();
}
void ball::show() {
	if (isVisible) {
		//chech time cycle
		if (isCovered && clock() - lastShown >= 1300) {
			isCovered = false;
			lastShown = clock();
		}
		else if (!isCovered && clock() - lastShown >= 300) {
			isCovered = true;
			lastShown = clock();
		}


		if (isCovered) {
			transimg(x, y, iunknown, iunknownx);
		}
		else {
			if (isPie) transimg(x, y, ipie, ipiex);
			else transimg(x, y, ibomb, ibombx);
		}
	}
}
void ball::hide() {
	repaintBlock(x, y, x + w, y + h, main_bg);
}



ballNode::ballNode(int x, bool isPie,
	IMAGE* iunknown, IMAGE* iunknownx,
	IMAGE* ipie, IMAGE* ipiex,
	IMAGE* ibomb, IMAGE* ibombx,
	IMAGE* main_bg) :
	item(isPie, x,
		iunknown, iunknownx,
		ipie, ipiex,
		ibomb, ibombx,
		main_bg) {}


ballList::ballList(IMAGE* iunknown, IMAGE* iunknownx,
	IMAGE* ipie, IMAGE* ipiex,
	IMAGE* ibomb, IMAGE* ibombx,
	IMAGE* main_bg) {
	head = new ballNode(0, 0, iunknown, iunknownx, ipie, ipiex, ibomb, ibombx, main_bg);
	head->next = NULL;
	tail = head;
	this->iunknown = iunknown;
	this->iunknownx = iunknownx;
	this->ipie = ipie;
	this->ipiex = ipiex;
	this->ibomb = ibomb;
	this->ibombx = ibombx;
	this->main_bg = main_bg;
}
void ballList::addNode(int x, bool isPie) {
	tail->next = new ballNode(x, isPie, iunknown, iunknownx, ipie, ipiex, ibomb, ibombx, main_bg);
	tail = tail->next;
	tail->next = NULL;
	tail->item.show();
}
void ballList::delNode() {
	ballNode* t = head->next;
	t->item.hide();
	head->next = t->next;
	delete t;
}
void ballList::show() {
	ballNode* p = head->next;
	while (p != NULL) {
		p->item.show();
		p = p->next;
	}
}
void ballList::hide() {
	ballNode* p = head->next;
	while (p != NULL) {
		p->item.hide();
		p = p->next;
	}
}
void ballList::move(int speed) {
	ballNode* p = head->next;
	while (p != NULL) {
		p->item.move(speed);
		p = p->next;
	}
}
void ballList::clear() {
	ballNode* t = head->next;
	while (t != NULL) {
		head->next = t->next;
		delete t;
		t = head->next;
	}
	tail = head;
}
ballNode* ballList::whoIsCaught(bowl* bowl0) {
	ballNode* p = head->next;
	while (p != NULL) {
		if (p->item.getY() >= 410) {
			if (bowl0->ifCaught(p)) return p;
		}
		p = p->next;
	}
	return NULL;
}
ballList::~ballList() {
	ballNode* t = head;
	while (t != NULL) {
		head = t->next;
		delete t;
		t = head;
	}
}