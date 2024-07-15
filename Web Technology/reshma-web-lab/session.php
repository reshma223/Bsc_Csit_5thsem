<?php
// Start or resume the session
session_start();

// Check if the page view count is set in the session
if (!isset($_SESSION['page_views'])) {
    $_SESSION['page_views'] = 1; // Initialize the count if not set
} else {
    $_SESSION['page_views']++; // Increment the count on each refresh
}

// Display the current page view count
$page_views = $_SESSION['page_views'];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Page View Counter</title>
</head>
<body>
    <h2>Welcome to the Page View Counter</h2>
    <p>This page has been viewed <?php echo $page_views; ?> times.</p>
</body>
</html>
