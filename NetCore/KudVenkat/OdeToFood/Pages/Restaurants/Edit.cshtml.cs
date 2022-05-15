using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using OdeToFood.Core;
using OdeToFood.Data;

namespace OdeToFood.Pages.Restaurants
{
    public class EditModel : PageModel
    {
        private readonly IRestaurantData restaurantData;
        private readonly IHtmlHelper htmlHelper;

        [BindProperty]
        public Core.Restaurants Restaurant { get; set; }

        public IEnumerable<SelectListItem> Cuisines { get; set; }
        public EditModel(IRestaurantData restaurantData, IHtmlHelper htmlHelper)
        {
            this.restaurantData = restaurantData;
            this.htmlHelper = htmlHelper;
        }
        public IActionResult OnGet(int? restaurantId)
        {
            Cuisines = htmlHelper.GetEnumSelectList<CuisineTypes>();
            if (restaurantId.HasValue)
            {
                Restaurant = restaurantData.GetRestaurantById(restaurantId.Value);
            }
            else 
            {
                Restaurant = new Core.Restaurants();
            }
            if (Restaurant == null) {
                return RedirectToPage("./NotFound");
            }
            return Page();
        }

        public IActionResult OnPost()
        {
            if (!ModelState.IsValid) 
            {
                Cuisines = htmlHelper.GetEnumSelectList<CuisineTypes>();
                return Page();
            }
            
            if (Restaurant.Id == 0) 
            {
                TempData["Message"] = "Restaurant Created!";
                Core.Restaurants result = restaurantData.AddNewRestaurant(Restaurant);
                restaurantData.Commit();
                return RedirectToPage("./Detail", new { restaurantId = result.Id });
            }
            else 
            {
                TempData["Message"] = "Restaurant Updated!";
                Core.Restaurants result = restaurantData.UpdateRestaurant(Restaurant);
                restaurantData.Commit();
                return RedirectToPage("./Detail", new { restaurantId = Restaurant.Id });
            }
        }
    }
}
