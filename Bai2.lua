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
    function find_name(name)
        local t = ""
        local tbl = {}
        gsub(name, "(%w+)", function (w) tinsert(%tbl, w) end)
        t = tbl[getn(tbl)]
        return strlower(t)
    end
    
    local tbd = {}
    
    local fileO = openfile("input2.txt","r")
    local file = openfile("input2.txt","r")
    local file2O = openfile("input3.txt","r")
    local file2 = openfile("input3.txt","r")
    
    local lines = getLines(fileO)
    local lines2 = getLines(file2O)
    
    for i = 1 , lines do
        tinsert(tbd,read(file,"*l"))
    end
    
    local dshs = {}
    for i = 1, getn(tbd),2 do
        tinsert(dshs, {diem = tbd[i], name = tbd[i+1]})
    end
    
    print("Danh sach hoc sinh: ")
    for i = 1, getn(dshs) do
        print("Ho ten: " .. dshs[i].name .. "\tDiem: " .. dshs[i].diem)
    end
    
    local tt = ""
    local td = 0
    for i = 1, getn(dshs) do
        if i ~= getn(dshs) then
            for j = i + 1, getn(dshs) do
                if find_name(dshs[i].name) > find_name(dshs[j].name) then
                    tt = dshs[i].name
                    dshs[i].name = dshs[j].name
                    dshs[j].name = tt
                    
                    td = dshs[i].diem
                    dshs[i].diem = dshs[j].diem
                    dshs[j].diem = td
                end
            end
        end
    end
    
    print("Danh sach hoc sinh sau khi sap xep: ")
    for i = 1, getn(dshs) do
        print("Ho ten: " .. dshs[i].name .. "\tDiem: " .. dshs[i].diem)
    end
    
    local tbNew = {}
    for i = 1 , lines2 do
        tinsert(tbNew,read(file2,"*l"))
    end
    
    for i = 1, getn(tbNew),2 do
        tinsert(dshs, {diem = tbNew[i], name = tbNew[i+1]})
    end
    
    print("Danh sach hoc sinh sau khi them: ")
    for i = 1, getn(dshs) do
        print("Ho ten: " .. dshs[i].name .. "\tDiem: " .. dshs[i].diem)
    end
    
    for i = 1, getn(dshs) do
        if i ~= getn(dshs) then
            for j = i + 1, getn(dshs) do
                if find_name(dshs[i].name) > find_name(dshs[j].name) then
                    tt = dshs[i].name
                    dshs[i].name = dshs[j].name
                    dshs[j].name = tt
                    
                    td = dshs[i].diem
                    dshs[i].diem = dshs[j].diem
                    dshs[j].diem = td
                end
            end
        end
    end
    
    print("Danh sach hoc sinh moi sau khi sap xep: ")
    for i = 1, getn(dshs) do
        print("Ho ten: " .. dshs[i].name .. "\tDiem: " .. dshs[i].diem)
    end
end
Main()