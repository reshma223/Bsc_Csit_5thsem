<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>File Content Display</title>
    <style>
        table {
            border-collapse: collapse;
            width: 100%;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
    </style>
</head>
<body>
    <h2>File Content Display</h2>

    <?php
    // Display provided data
    echo "<p><strong>Name:</strong> Reshma</p>";
    echo "<p><strong>Class:</strong> 12</p>";
    echo "<p><strong>Roll No:</strong> 3</p>";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if (isset($_FILES["file"]) && $_FILES["file"]["error"] == 0) {
            $file = $_FILES["file"]["tmp_name"];
            
            // Read file content
            $content = file_get_contents($file);

            // Explode content into rows
            $rows = explode("\n", $content);

            // Display content in a table
            echo "<table>";
            foreach ($rows as $row) {
                echo "<tr>";
                $columns = explode("\t", $row);
                foreach ($columns as $column) {
                    echo "<td>" . htmlspecialchars($column) . "</td>";
                }
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "<p>Error uploading the file.</p>";
        }
    } else {
        echo "<p>Invalid request.</p>";
    }
    ?>
    
</body>
</html>
