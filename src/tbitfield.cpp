// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len <= 0)
		throw len;
	BitLen=len;
	MemLen = len / 32 + 1;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = 0;
	}
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = bf.pMem[i];
	}
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n/32;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1<<(n%32);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	int i = GetMemIndex(n);
	TELEM m = GetMemMask(n);
	pMem[i] |= m;
}

void TBitField::ClrBit(const int n) // очистить бит
{
	int i = GetMemIndex(n);
	TELEM m = GetMemMask(n);
	pMem[i] = pMem[i] & (~m);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	int i = GetMemIndex(n);
	TELEM m = GetMemMask(n);
	return pMem[i] & m;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if (MemLen != bf.MemLen)
	{
		delete[] pMem;
		pMem = new TELEM[MemLen];
		MemLen = bf.MemLen;
	}
	BitLen = bf.BitLen;
	for (int i = 0; i < MemLen; i++)
		pMem = bf.pMem;
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (MemLen != bf.MemLen || BitLen!=bf.BitLen)
	{
		return 0;
	}
	for (int i = 0; i < MemLen; i++)
	{
		if (pMem[i] != bf.pMem[i])
			return 0;
	}
	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	if (MemLen != bf.MemLen || BitLen != bf.BitLen)
	{
		return 1;
	}
	for (int i = 0; i < MemLen; i++)
	{
		if (pMem[i] != bf.pMem[i])
			return 1;
	}
	return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	TBitField res(10);
	return res;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	TBitField res(10);
	return res;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField res(10);
	return res;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	return ostr;
}
