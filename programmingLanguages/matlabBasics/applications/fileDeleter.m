% MATLAB automation to delete user-specified extension files 

% Prompt the user to input the extension (e.g., 'bak', 'txt', 'tmp')
ext = input('Enter the file extension to delete (without the dot): ', 's');

% Build the search pattern for the specified extension
searchPattern = sprintf('**\\*.%s', ext);

% Find all files matching the extension in the current folder and subfolders
targetFiles = dir(fullfile(searchPattern));
count = numel(targetFiles);

% Delete each file found
for i = 1:count
    delete(fullfile(targetFiles(i).folder, targetFiles(i).name));
end

fprintf('Deleted %d files with .%s extension.\n', count, ext);
