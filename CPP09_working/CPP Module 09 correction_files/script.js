function closePopup() {
    // Get elements
    const popup = document.getElementById('popup');
    const overlay = document.getElementById('overlay');
    
    // Add closing animation
    popup.classList.add('fade-out');
    overlay.classList.add('fade-out');
    
    // Wait for animation to complete before hiding
    setTimeout(() => {
        popup.style.display = 'none';
        overlay.style.display = 'none';
        
        // Remove animation classes for next use
        popup.classList.remove('fade-out');
        overlay.classList.remove('fade-out');
        
        // Reset form and call typeLogin
        resetForm();
        typeLogin();
    }, 300); // Match this duration with your CSS animation time
    
    // Dispatch custom event
    const popupClosedEvent = new Event('popupClosed');
    document.dispatchEvent(popupClosedEvent);
}

// Helper function to reset form if needed
function resetForm() {
    const form = document.querySelector('#popup form');
    if (form) {
        form.reset();
    }
}