dofile("Define.lua")

tbB = tbA
tinsert(tbB, {name = "Long Thach - Ha", soluong = 1, hsd = "", ti_le = 1} )
tinsert(tbB, {name = "Nhan 20 van Bac", soluong = 200000, hsd = "", ti_le = 0.3} )

local idA = tbA:getId()
tbA:showResult(tbA:getName(idA),tbA:getTL(idA))

local idB = tbB:getId()
tbB:showResult(tbB:getName(idB),tbB:getTL(idB))