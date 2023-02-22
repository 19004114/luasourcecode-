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
    local lines = getLines(fileO)
    
    for i = 1 , lines do
        tinsert(tbl,read(file,"*l"))
    end
end