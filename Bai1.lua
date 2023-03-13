function Main()
    function getLines(file)
        local check = true
        local lines = 0
        while check == true do
            if read(file,"*l") ~= nil then
                lines = lines + 1
            else
                break
            end
        end
        return lines
    end
    
    local tbl = {}
    
    local fileO = openfile("D:\\luaex\\input.txt","r")
    local file = openfile("D:\\luaex\\input.txt","r")
    local lines = getLines(fileO)
    
    for i = 1 , lines do
        tinsert(tbl,read(file,"*l"))
    end
    
    local min = tbl[1]
    local max = tbl[1]
    local t = 0
    local tbc = 0
    
    for i = 1, getn(tbl) do
        if tonumber(min) > tonumber(tbl[i]) then
            min = tbl[i]
        end
        if tonumber(max) < tonumber(tbl[i]) then
            max = tbl[i]
        end
        t = t + tbl[i]
    end
    tbc = t/getn(tbl)
    
    print("Phan tu nho nhat: " .. min)
    print("Phan tu lon nhat: " .. max)
    print("Trung binh cong cac phan tu: " .. tbc)
    
    write("Cac phan tu nho hon trung binh cong: ")
    for i = 1, getn(tbl) do
        if tonumber(tbl[i]) < tbc then
            write(tbl[i] .. "\t")
        end
    end
    
    write("\nCac phan tu lon hon trung binh cong: ")
    for i = 1, getn(tbl) do
        if tonumber(tbl[i]) > tbc then
            write(tbl[i] .. "\t")
        end
    end
end
Main()