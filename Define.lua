TB = {}

TB.A = {
    {name = "Dang Long Thach - Ha", soluong = 1, hsd = "", ti_le = 10},
    {name = "Dang Long Thach - Thuong", soluong = 1, hsd = "", ti_le = 0.3},
    {name = "Do Pho Dang Long - Khoi", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Hai", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Yeu Dai", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Ho Uyen", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Hang Lien", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Boi", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Thuong Gioi", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Ha Gioi", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Y", soluong = 1, hsd = "", ti_le = 0.008},
    {name = "Do Pho Dang Long - Khi Gioi", soluong = 1, hsd = "", ti_le = 0.003},
    {name = "Dang Long Trung Luyen Ngoc", soluong = 1, hsd = "", ti_le = 0.3},
    {name = "Hon Nguyen Chan Don", soluong = 1, hsd = "", ti_le = 0.2},
    {name = "Ho Mach Don", soluong = 25, hsd = "", ti_le = 70.29},
}

function TB:rand()
    return random(1,100000)
end

function TB:getId(tbA)
    local r = TB:rand()
    local index = 0
    local nRate = 0
    
    for i = 1, getn(tbA) do
        nRate = nRate + tbA[i].ti_le * 1000
        if tonumber(nRate) >= tonumber(r) then
            index = i
            return index
        end      
    end
    return index
end

function TB:showItem()
    for i = 1, getn(self.A) do
        print("Ten Vat Pham: " .. self.A[i].name .. "\tSo luong: " .. self.A[i].soluong .. "\tHan Su Dung: " .. self.A[i].hsd .. "\tTi le: " .. self.A[i].ti_le)
    end
end


function TB:getName(id)
    for i = 1, getn(self.A) do
        if id == i then
            return self.A[i].name
        end
    end
end

function TB:getTL(id)
    for i = 1, getn(self.A) do
        if id == i then
            return tonumber(self.A[i].ti_le)
        end
    end
end

function TB:showResult(tbA,index)
    if tonumber(index) == 0 then
        print("Chuc ban may man lan sau")
    elseif tonumber(index) > 0 then
        if tonumber(tbA[index].ti_le) <= 0.01 then
            print("Chuc mung dai hiep may man trung duoc vat pham " .. tbA[index].name)
        elseif tonumber(tbA[index].ti_le) > 0.01 then
            print("Nhan duoc vat pham " .. tbA[index].name)
        end
    end
end

function TB:copy(tb)
    local tbNew = {}
    for i, v in tb do
        tbNew[i] = v
        if type(v) == "table" then
            TB:copy(v)
        end
    end
    return tbNew
end