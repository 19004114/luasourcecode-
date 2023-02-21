dofile("Define.lua")

function TB:Main()
    local idx = self:getId(self.A)
    self:showResult(self.A,idx)
end

tbB = {}

function tbB:Main()
    self = TB:copy(TB)
    tinsert(self.A, {name = "Long Thach - Ha", soluong = 1, hsd = "", ti_le = 1} )
    tinsert(self.A, {name = "Nhan 20 van Bac", soluong = 200000, hsd = "", ti_le = 0.3} )
    local idx = self:getId(self.A)
    self:showResult(self.A,idx)
end

tbB:Main()