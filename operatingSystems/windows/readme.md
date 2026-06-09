# Windows

Windows is not only the most popular operating system (OS) running in desktops and laptops, but the system that defined the standard for common user, due to incorporation of interfaces since the beggining that don't require high expertise on computer programming to be used.

It was the first OS I ever used and, although is no longer installed in any of my personal computers, it is still my work tool at the office.

Here is a collection of articles I wrote and also prompted to AI about Windows and the art of patience with its bugs.

---

## Debugging session

### Google Chrome Update

I worked in a company that requested the Google Chrome update by accessing the menu option `Help -> About Google Chrome`. In this section, Google Chrome verifies current software version, check and install updates. To make it easier, I requested a batch file to Gemini in order to execute this task, which resulted in the answer below.

To open Google Chrome directly to the "About Google Chrome" page, you cannot use the traditional menu-clicking simulation in a standard batch file. Instead, you must pass the exact [internal Chrome URL](https://support.google.com/chrome/thread/383089112?hl=en&msgid=383089612) as a command-line argument. [1, 2] 
The direct URL for this menu path is chrome://settings/help.
Here is the code and instructions to create the batch file for Windows 11.

#### Step 1: The Batch Script Code

Open Notepad, copy the block of code below, and paste it inside: [3] 

```batch
@echo off
title Launching Chrome About Page

echo Searching for Google Chrome installation...

:: Define the targeting URL
set "chromeURL=chrome://settings/help"

:: Check standard 64-bit installation path
if exist "C:\Program Files\Google\Chrome\Application\chrome.exe" (
    start "" "C:\Program Files\Google\Chrome\Application\chrome.exe" %chromeURL%
    goto success
)

:: Check standard 32-bit installation path
if exist "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe" (
    start "" "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe" %chromeURL%
    goto success
)

:: Fallback if path is custom but register entry exists
where chrome >nul 2>&1
if %errorLevel% eq 0 (
    start chrome %chromeURL%
    goto success
)

echo.
echo ERROR: Google Chrome could not be found on this system.
pause
exit /b

:success
echo.
echo Chrome successfully launched to the About Page!
timeout /t 3 >nul
exit
```

#### Step 2: Save the File

   1. In Notepad, click File > Save As....
   2. Click the Save as type dropdown menu and select All Files (.).
   3. Name the file OpenChromeAbout.bat.
   4. Choose your preferred save location and click Save. [3] 

#### Step 3: Run the Script

Double-click the OpenChromeAbout.bat file. It will immediately open Chrome (or open a new tab if Chrome is already active) and navigate directly to the Help page, where it will display your current software version and automatically scan for updates. [3, 4, 5, 6, 7] 

[1] [https://groups.google.com](https://groups.google.com/a/chromium.org/g/chromium-discuss/c/nGAKdlNAMTQ)
[2] [https://www.geeksforgeeks.org](https://www.geeksforgeeks.org/techtips/how-to-open-google-chrome-using-cmd/)
[3] [https://www.youtube.com](https://www.youtube.com/watch?v=Tr2PXAk5_LQ)
[4] [https://www.youtube.com](https://www.youtube.com/watch?v=IQpc3pJM49g)
[5] [https://www.youtube.com](https://www.youtube.com/watch?v=HW7Z0a4-WqU&t=1)
[6] [https://stackoverflow.com](https://stackoverflow.com/questions/19352463/writing-a-batch-file-that-opens-a-chrome-url)
[7] [https://support.google.com](https://support.google.com/chrome/?hl=en)

Since this solution worked relatively well, I questioned regarding a more general approach to open websites via batch file and got this answer:

To open Google Chrome and access a specific website via a batch file, use the start command followed by the chrome process name and your target URL. [1, 2] 
Assuming you want to launch the browser, load a website, and automatically close the background command prompt window once launched, use the following template.

#### 1. The Code
Copy this code into a text editor like Notepad: [3] 

```batch
@echo off
:: Launches Google Chrome and opens the specified website
start chrome "https://wikipedia.org"
exit
```

#### 2. How to Save and Run It

   1. Open Notepad (or any text editor).
   2. Paste the code snippet above.
   3. Replace https://wikipedia.org with your desired web address.
   4. Click File > Save As...
   5. In the "Save as type" dropdown, choose All Files (.).
   6. Name your file with a .bat extension (e.g., open_site.bat).
   7. Double-click the saved file to run it. [4, 5] 

#### 3. Common Variations [6]

* Open multiple websites in separate tabs:

```batch 
@echo off
start chrome "https://google.com" "https://wikipedia.org"
exit
```

* Open Chrome in Incognito mode:

```batch
@echo off
start chrome --incognito "https://wikipedia.org"
exit
```

* Wait for Chrome to load before continuing the script:
If you are chaining this with other commands (like the time delays discussed previously), add a timeout after launching:

```batch
@echo off
start chrome "https://wikipedia.org"
timeout /t 3 /nobreak >nul
echo Chrome has been launched!
pause
```

[1] [https://www.reddit.com](https://www.reddit.com/r/Batch/comments/nd6ohl/how_to_make_a_batch_file_open_a_web_page_you_type/)
[2] [https://superuser.com](https://superuser.com/questions/887640/how-to-make-batch-file-to-open-specific-profiles-in-google-chrome)
[3] [https://www.facebook.com](https://www.facebook.com/howtogeek/posts/you-can-turn-chromes-address-bar-into-a-notepad-with-one-line-of-text/1383654790464191/)
[4] [https://www.sce.carleton.ca](http://www.sce.carleton.ca/faculty/chinneck/Useful/Using%20DOS%20Batch%20Files%20to%20Run%20Experiments%20on%20Windows.htm)
[5] [https://www.bubsites.com](https://www.bubsites.com/open-the-windows-hosts-file-in-an-elevated-notepad-instance-with-a-batch-script/)
[6] [https://superuser.com](https://superuser.com/questions/1633874/open-a-new-tab-in-chrome-or-switch-to-an-existing-one-with-the-same-url-cmd)

