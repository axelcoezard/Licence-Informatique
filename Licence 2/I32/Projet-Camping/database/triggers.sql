CREATE OR REPLACE FUNCTION public.addrestaurantplace()
    RETURNS trigger
    LANGUAGE plpgsql
AS $function$
	BEGIN
		update "Restaurant_info" set "nb_placeRestante" = "nb_placeRestante" - new.nb_place where id_restaurant = new.id_restaurant;
		return new;
	END;
$function$;
;

create trigger ajoutplace after
insert on public."Place_restaurant"
for each row execute procedure addrestaurantplace();


CREATE OR REPLACE FUNCTION public.removerestaurantplace()
 RETURNS trigger
 LANGUAGE plpgsql
AS $function$
	BEGIN
		update "Restaurant_info" set "nb_placeRestante" = "nb_placeRestante" + old.nb_place where id_restaurant = old.id_restaurant;
		return old;
	END;
$function$
;


create trigger removeplace before
delete on public."Place_restaurant"
for each row execute procedure removerestaurantplace();
