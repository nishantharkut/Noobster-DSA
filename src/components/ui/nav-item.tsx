
import React from 'react';
import { Link, useLocation } from 'react-router-dom';
import { LucideIcon } from 'lucide-react';
import { cn } from '@/lib/utils';
import {
  Tooltip,
  TooltipContent,
  TooltipProvider,
  TooltipTrigger,
} from '@/components/ui/tooltip';

interface NavItemProps {
  href: string;
  icon: LucideIcon;
  label: string;
  id?: string;
  variant?: 'desktop' | 'mobile';
  onClick?: () => void;
}

export const NavItem: React.FC<NavItemProps> = ({
  href,
  icon: Icon,
  label,
  id,
  variant = 'desktop',
  onClick
}) => {
  const location = useLocation();
  const isActive = location.pathname === href;

  const baseClasses = cn(
    "flex items-center gap-2 text-sm font-medium transition-all duration-200",
    "focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2",
    "rounded-xl"
  );

  const desktopClasses = cn(
    baseClasses,
    "px-3 py-2 hover:bg-accent hover:text-accent-foreground",
    isActive 
      ? "bg-primary/10 text-primary border border-primary/20 shadow-sm" 
      : "text-muted-foreground hover:text-foreground"
  );

  const mobileClasses = cn(
    baseClasses,
    "px-4 py-3 hover:bg-accent hover:text-accent-foreground",
    isActive 
      ? "bg-primary/10 text-primary border border-primary/20" 
      : "text-muted-foreground hover:text-foreground"
  );

  const className = variant === 'desktop' ? desktopClasses : mobileClasses;

  const linkContent = (
    <Link
      to={href}
      id={id}
      className={className}
      onClick={onClick}
      role="menuitem"
      aria-label={`Navigate to ${label}`}
      aria-current={isActive ? 'page' : undefined}
    >
      <Icon className="h-4 w-4" aria-hidden="true" />
      {variant === 'mobile' && <span>{label}</span>}
    </Link>
  );

  // For desktop, wrap with tooltip
  if (variant === 'desktop') {
    return (
      <TooltipProvider>
        <Tooltip>
          <TooltipTrigger asChild>
            {linkContent}
          </TooltipTrigger>
          <TooltipContent>
            <p>{label}</p>
          </TooltipContent>
        </Tooltip>
      </TooltipProvider>
    );
  }

  // For mobile, return without tooltip
  return linkContent;
};
